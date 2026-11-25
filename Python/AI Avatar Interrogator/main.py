import speechToText as stt
import query
from avatarInterrogator import chatSession as cs
import textToSpeech as tts
import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QTextEdit, QLabel
from PyQt5.QtCore import Qt, QThread, pyqtSignal

class RecordingThread(QThread):
    transcript_ready = pyqtSignal(str)  # Signal to send the transcript back to the GUI
    error_occurred = pyqtSignal(str)    # Signal to notify the GUI about errors

    def __init__(self, session_id):
        super().__init__()
        self.session_id = session_id
        self.running = True

    def run(self):
        try:
            mic_manager = stt.ResumableMicrophoneStream(stt.SAMPLE_RATE, stt.CHUNK_SIZE)
            with mic_manager as stream:
                stream.running = True
                self.stream = stream
                client = stt.speech.SpeechClient()
                config = stt.speech.RecognitionConfig(
                    encoding=stt.speech.RecognitionConfig.AudioEncoding.LINEAR16,
                    sample_rate_hertz=stt.SAMPLE_RATE,
                    language_code="en-US",
                    max_alternatives=1,
                )
                streaming_config = stt.speech.StreamingRecognitionConfig(
                    config=config, interim_results=True
                )

                audio_generator = stream.generator()
                requests = (
                    stt.speech.StreamingRecognizeRequest(audio_content=content)
                    for content in audio_generator
                )
                responses = client.streaming_recognize(streaming_config, requests)

                # Process responses while checking `self.running`
                for response in responses:
                    if not stream.running:
                        # Send last response thru before dying
                        stt.listen_print_loop([response], stream)
                        stream.stop()
                        break  # Exit loop if stopped
                    stt.listen_print_loop([response], stream)

                # if not self.running:
                #     # close remaining resources and stop stream
                #     stream.closed = True
                #     self.transcript_ready.emit("Recording stopped.")
                #     return

                # Load the transcript file after stopping
                try:
                    transcript_data = query.getQuery(stream.filename)
                    self.transcript_ready.emit(transcript_data)
                except Exception as e:
                    self.error_occurred.emit(f"Error loading transcript: {str(e)}")
        except Exception as e:
            self.error_occurred.emit(f"Error during recording: {str(e)}")

    def stop(self):
        """Stop the recording thread."""
        self.running = False
        self.stream.running = False
        self.quit()
        print(f"Waiting for thread to close...")
        self.wait()


class AvatarGUI(QWidget):
    def __init__(self):
        super().__init__()
        self.init_ui()
        self.session_id = stt.setSessionID()
        self.is_recording = False # track recording state
        self.mic_manager = None # ref to microphone manager
        self.recording_thread = None # thread to handle recording

    def init_ui(self):
        self.setWindowTitle("AI Avatar Interrogator")
        self.setGeometry(100, 100, 400, 500)

        self.layout = QVBoxLayout()

        # Record Button
        self.record_button = QPushButton("Start Recording")
        self.record_button.clicked.connect(self.record_speech)
        self.layout.addWidget(self.record_button)

        # Transcript and TextEdit
        self.transcript_label = QLabel("Transcript:")
        self.layout.addWidget(self.transcript_label)

        self.transcript_edit = QTextEdit()
        self.layout.addWidget(self.transcript_edit)

        # Confirm button
        self.confirm_button = QPushButton("Confirm")
        self.confirm_button.clicked.connect(self.send_to_server)
        self.layout.addWidget(self.confirm_button)

        # Display response
        self.response_label = QLabel("Server Response:")
        self.layout.addWidget(self.response_label)

        self.response_display = QLabel()
        self.response_display.setWordWrap(True)
        self.response_display.setAlignment(Qt.AlignTop)
        self.layout.addWidget(self.response_display)

        self.setLayout(self.layout)

    def record_speech(self):
        if not self.recording_thread or not self.recording_thread.isRunning():
            # Start recording
            self.recording_thread = RecordingThread(self.session_id)
            self.recording_thread.transcript_ready.connect(self.display_transcript)
            self.recording_thread.error_occurred.connect(self.display_error)
            self.recording_thread.start()
            self.record_button.setText("Stop Recording")
            self.response_display.setText("Recording...")
        else:
            # Stop recording
            self.recording_thread.stop()
            self.recording_thread = None
            self.record_button.setText("Start Recording")
            self.response_display.setText("Recording stopped.")

    def display_transcript(self, transcript):
        print(f"Displaying transcript: {transcript}")
        self.transcript_edit.setText(transcript)

    def display_error(self, errorMessage):
        self.response_display.setText(errorMessage)

    def start_recording(self):
        """Record speech"""
        try:
            self.mic_manager = stt.ResumableMicrophoneStream(stt.SAMPLE_RATE, stt.CHUNK_SIZE)
            self.response_display.setText("Recording...")

            with self.mic_manager as stream:
                self.stream = stream
                self.responses = stt.speech.SpeechClient().streaming_recognize(
                    stt.speech.StreamingRecognitionConfig(
                        config=stt.speech.RecognitionConfig(
                            encoding=stt.speech.RecognitionConfig.AudioEncoding.LINEAR16,
                            sample_rate_hertz=stt.SAMPLE_RATE,
                            language_code="en-US",
                            max_alternatives=1,
                        ),
                        interim_results=True,
                    ),
                    (stt.speech.StreamingRecognizeRequest(audio_content=content)
                     for content in stream.generator()),
                )
                # Process responses asynchronously
                stt.listen_print_loop(self.responses, stream)

                # # Add generated transcript to transcript field
                # with open(stream.filename, 'r') as file:
                #     data = file.read()
                # self.transcript_edit.setText(data)
        except Exception as e:
            self.response_display.setText(f"Error during recording: {str(e)}")

    def stop_recording(self):
        """Stop recording"""
        if self.mic_manager:
            self.mic_manager.closed = True
            self.mic_manager = None
            self.response_display.setText("Recording stopped.")

            # Load transcript from generated file and display
            try:
                print(f"Transcript file path: {self.stream.filename}")
                with open(self.stream.filename, 'r') as file:
                    transcript_data = file.read()
                self.transcript_edit.setText(transcript_data)
            except Exception as e:
                self.response_display.setText(f"Error loading transcript: {str(e)}")

    def send_to_server(self):
        """ Send transcript to server"""
        transcript = self.transcript_edit.toPlainText()
        try:
            # # save edited transcript to temp json
            # filename = "edited_transcript.json"
            # with open(filename, "w") as f:
            #     f.write(transcript)
            #
            # # process into query
            # query_text = query.getQuery(filename)

            # get server response, use chatSession funcs
            response = cs.returnAnswer(transcript)

            # display response
            self.response_display.setText(f"Server Response: {response}")
            self.playAudio(response)
        except Exception as e:
            self.response_display.setText(f"Error communicating with server: {str(e)}")

    def playAudio(self, response):
        tts.writeToMP3(response)
        tts.play()


if __name__ == "__main__":
    print(sys.prefix != sys.base_prefix)
    sessionID = stt.setSessionID()
    # while True:
    #     key = keyboard.read_key()
    #     if key == 'esc':
    #         break
    #     elif key == 's':
    #         speechToText.main()

    app = QApplication(sys.argv)
    window = AvatarGUI()
    window.show()
    sys.exit(app.exec_())
