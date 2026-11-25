import json
import os
import uuid
from datetime import datetime

def isEmpty(filename):
    with open(filename, 'r') as f:
        return len(f.read()) == 0

def getID():
    id = uuid.uuid4()
    return id

def getCurrent():
    now = datetime.now()
    return now

def getCurrentDate(date):
    return str(date.year) + "_" + str(date.month) + "_" + str(date.day) + "_"

def getCurrentTime(date):
    return str(date.hour) + "_" + str(date.minute) + "_" + str(date.second)

def toJson(corrected_time, transcript, fileName):
    # file_id = getID()
    # now = getCurrent()
    # now_date = getCurrentDate(now)
    # now_time = getCurrentTime(now)
    #
    # # fileName = now_date + 'output_' + now_time + '.json'
    # fileName = "output.json"

    if not os.path.exists(fileName):
        with open(fileName, 'w') as file:
            json.dump({}, file)
        file.close()
    else:
        with open(fileName, 'r') as file:
            data = json.load(file)
        file.close()
        # # clean out file FOR NOW
        # if data != {}:
        #     data = {}
        # use time as keys -- should be unique
        #data[time] = transcript
        data[corrected_time] = transcript

        # with open('data.json', 'w') as file:
        #     json.dump(data, file, indent=4)
        with open(fileName, 'w') as file:
            json.dump(data, file)
        file.close()

    #check if json file is empty (has just been created)
    # if isEmpty(fileName):
    #     file = open(fileName, "w")
    #     json.dump({}, file)
    #     file.close()

    file = open(fileName, 'r')
    data = json.load(file)
    file.close()

    #data = responses

    data[corrected_time] = transcript
    #
    # file = open(fileName, 'w')
    # json.dump(data, file, indent=4)
    # file.close()
    with open(fileName, "r+") as file:
        # data = json.load(file)
        # data[corrected_time] = transcript

        # file.seek(0) # send pointer back to beginning of file
        json.dump(data, file, indent=4)
        # file.truncate() # truncate if contents are shorter than prev

    #print("Data saved to", fileName)
    file.close()