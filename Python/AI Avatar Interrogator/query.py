import os
import json

def getQuery(file):
    query = ""
    f = open(file, "r")
    data = json.load(f)
    f.close()
    # append to query
    for i in data:
        text = data[i]
        if text != ' exit' and text != ' quit':
            query += data[i]

    return query

# def sendQuery(query):
#     # response is a response object of some kind, can isolate just the text
#     genai.configure(api_key="AIzaSyCgs-MFr92Qx7Otpc-sBQxhJNIYA5L2lIY")
#     model = genai.GenerativeModel(model_name="gemini-1.5-flash",
#                                   system_instruction="You are a 32-year-old nurse under suspicion of diverting drugs from your hospital and pocketing it for your own needs.  You did not steal anything, however, and are trying your best to prove your innocence.")
#     response = model.generate_content(query)
#
#     return response.text

# save separate profiles, use one at random
# turn json files into queries
# keep optimization in mind but focus on functionality first
