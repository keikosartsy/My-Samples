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
