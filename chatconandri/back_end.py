import sys
import time
from modules import get_key, get_previous_key, get_next_key, deEmojify
import tkinter.messagebox as mbox

msgs = {}
occur = ""
current = "--/--/--"

def setup():
    f = open("chat.txt", "r")
    temp = f.readlines()
    f.close()

    for x in temp:
        msgs.update({x[10:] : x[0:8]})


def find_message(values):
    global occur
    global current
    date = str(values[0]) + "/" + str(values[1]) + "/" + str(values[2])
    occur = get_key(date, msgs) #get the occurrence
    if occur == None:
        mbox.showinfo("Avviso",
        "Nessun messaggio corrispondente per questa data.")
        current = "--/--/--"
        return -1
    else:
        current = date
        ret_dict = {"time":occur[0:8],
                    "text":occur[16:],
                    "sender":occur[9:occur.find(': ')],
                    "date":date}
        #create a dict. with all the informations of the message
        return ret_dict

def backwards():
    global occur
    prev = get_previous_key(occur, msgs) #get the prev. message
    date = msgs.get(prev) #set the new date
    occur = prev #change the occur to use it as a mark
    ret_dict = {"time":prev[0:8],
                "text":prev[16:],
                "sender":prev[9:14],
                 "date":date} #create a dict with all the new informations
    return ret_dict

def forwards():
    global occur
    next = get_next_key(occur, msgs)
    date = msgs.get(next)
    occur = next
    ret_dict = {"time":next[0:8],
                "text":next[16:],
                "sender":next[9:14],
                 "date":date}
    return ret_dict
