from google.cloud import texttospeech
import os
import sys
import pygame

# text = "Hello. My name is Samantha Davis, and welcome to the AAI Interrogator."
client = texttospeech.TextToSpeechClient()

def getInput(text):
    input_text = texttospeech.SynthesisInput(text=text)
    return input_text

def writeToMP3(text):
    input = getInput(text)
    voice = texttospeech.VoiceSelectionParams(
        language_code="en-US",
        name="en-US-Standard-C",
        ssml_gender=texttospeech.SsmlVoiceGender.FEMALE
    )

    audio_config = texttospeech.AudioConfig(
        audio_encoding=texttospeech.AudioEncoding.MP3
    )

    response = client.synthesize_speech(
        request={"input": input, "voice": voice, "audio_config": audio_config}
    )
    with open("output.mp3", "wb") as out:
        out.write(response.audio_content)
        print('Audio content written to file "output.mp3"')

def play():
    pygame.mixer.init()
    filePath = os.getcwd() + os.path.sep + "output.mp3"
    pygame.mixer.music.load(filePath)
    pygame.mixer.music.play()
    while pygame.mixer.music.get_busy():
        pygame.time.Clock().tick(10)
    pygame.mixer.music.unload() # free up audio file