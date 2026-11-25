import json
import os

def write(query, answer, fileName):
    f = open(fileName, "a")
    f.write("User: " + query)
    f.write("\nAgent: " + answer)
    f.close()