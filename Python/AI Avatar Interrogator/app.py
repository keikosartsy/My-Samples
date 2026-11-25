from flask import Flask, request, jsonify
import speechToText as stt
import query
import chatSession as cs
import textToSpeech as tts

app = Flask(__name__)

@app.route("/")
def home():
    return "This is the web app!"
    
def run_flask():
    app.run(host="0.0.0.0", port=5000, debug=False, use_reloader=False)

@app.route("/start_recording", methods=["POST"])
def start_recording():
    try:
        session_id = stt.setSessionID()
        mic_manager = stt.ResumableMicrophoneStream(stt.SAMPLE_RATE, stt.CHUNK_SIZE)
        with mic_manager as stream:
            client = stt.speech.SpeechClient()
            config = stt.speech.RecognitionConfig(
                encoding=stt.speech.RecognitionConfig.AudioEncoding.LINEAR16,
                sample_rate_hertz=stt.SAMPLE_RATE,
                language_code="en-US",
                max_alternatives=1,
            )
            streaming_config = stt.speech.StreamingRecognitionConfig(
                config=config, interim_results=False
            )

            audio_generator = stream.generator()
            requests = (
                stt.speech.StreamingRecognizeRequest(audio_content=content)
                for content in audio_generator
            )
            responses = client.streaming_recognize(streaming_config, requests)
            for response in responses:
                stt.listen_print_loop([response], stream)

        transcript = query.getQuery(stream.filename)
        return jsonify({"transcript": transcript})
    except Exception as e:
        return jsonify({"error": str(e)}), 500

@app.route("/send_to_server", methods=["POST"])
def send_to_server():
    try:
        data = request.get_json()
        transcript = data.get("transcript", "")
        response = cs.returnAnswer(transcript)
        return jsonify({"response": response})
    except Exception as e:
        return jsonify({"error": str(e)}), 500

@app.route("/play_audio", methods=["POST"])
def play_audio():
    try:
        data = request.get_json()
        response_text = data.get("response", "")
        tts.writeToMP3(response_text)
        tts.play()
        return jsonify({"message": "Audio played successfully."})
    except Exception as e:
        return jsonify({"error": str(e)}), 500

if __name__ == "__main__":
    print("Attempting to start app.py...")
    run_flask()
