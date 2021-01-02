import tkinter as tk
from time import sleep
import tkinter.messagebox as mbox
import back_end as bk
from datetime import datetime
from modules import get_next_key
from modules import get_previous_key

bk.setup()

def setter(time, text, sender, date):
    if sender == "andri": #check the sender
        left_bubble.delete(1.0, "end")
        left_bubble.insert(tk.INSERT, text)
        right_bubble.delete(1.0, "end")
        right_bubble.insert(tk.INSERT, "")
        left_time.config(text="")
        right_time.config(text=time)
    else:
        left_bubble.delete(1.0, "end")
        left_bubble.insert(tk.INSERT, "")
        right_bubble.delete(1.0, "end")
        right_bubble.insert(tk.INSERT, text)
        left_time.config(text=time)
        right_time.config(text="")
    current_date.config(text=date)

def set_error():
    left_bubble.delete(1.0, "end")
    left_bubble.insert(tk.INSERT, f"""Messaggi di Andri""")
    right_bubble.delete(1.0, "end")
    right_bubble.insert(tk.INSERT, f"""Messaggi di Laura""")
    left_time.config(text="--:--:--")
    right_time.config(text="--:--:--")
    current_date.config(text="--/--/--")

def update_b():
    res = bk.backwards()
    setter(res['time'], res['text'], res['sender'], res['date'])


def update_f():
    res = bk.forwards()
    setter(res['time'], res['text'], res['sender'], res['date'])


def restart():
    res = list(bk.msgs.values())[0]
    res = res.split('/')
    res = bk.find_message(res)
    setter(res['time'], res['text'], res['sender'], res['date'])


def check():
    date = find.get().split('/') #split the date to have a list
    date.reverse() #reversing the date to use it with datetime
    try:
        datetime(int(date[0]), int(date[1]), int(date[2])) #verify the date
        date.reverse() #re-reverse the date to bring it back to the original
        res = bk.find_message(date) #return the function find_message to res var
        if res == -1: #error: no message found for that date
            set_error() #setting all blank
        else:
            setter(res['time'], res['text'], res['sender'], bk.current)
    except ValueError:
        set_error()
        mbox.showerror("Errore", "Non hai inserito una data valida.")
    except IndexError:
        set_error()
        mbox.showerror("Errore", "Non hai scritto nulla di sensato.")
        

win = tk.Tk()
win.geometry("800x500")
win.configure(bg="#b0e7ff")
win.resizable(False, False)
win.iconphoto(False, tk.PhotoImage(file="win_icon.png"))


#Configs
icon = tk.PhotoImage(file="finder.png")
icon = icon.subsample(28)

left_arrw = tk.PhotoImage(file="arrow.png")
right_arrw = tk.PhotoImage(file="arrow2.png")

current_date = tk.Label(text=bk.current, relief="sunken")
current_date.place(x=680, y=30, width=90, height=28)

#Entry
find = tk.Entry(bg="#9abded", highlightbackground="black")
find.place(x=350, y=30, width=100, height=28)

#Buttons
submit = tk.Button(image=icon, highlightbackground="black",
command=check).place(
x=470, y=30, width=28, height=28)

restart = tk.Button(text="Inizio", highlightbackground="black", command=restart).place(
x=30, y=30, width=70, height=28)

prev = tk.Button(image=left_arrw, highlightbackground="black", command=update_b).place(
x=367, y=452, width=28, height=28)

next = tk.Button(image=right_arrw, highlightbackground="black", command=update_f).place(
x=410, y=452, width=28, height=28)

#Bubbles
left_bubble = tk.Text(borderwidth=2, relief="groove", bg="#9abded")
left_bubble.insert(tk.INSERT, f"""Messaggi di Andri""")
left_bubble.place(x=28, y=275, width=650, height=150)

left_time = tk.Label(text="--:--:--", relief="ridge", bg="#9abded")
left_time.place(x=28, y=225, width=60, height=25)

right_bubble = tk.Text(borderwidth=2, relief="groove", bg="#9abded")
right_bubble.insert(tk.INSERT, f"""Messaggi di Laura""")
right_bubble.place(x=125, y=100, width=650, height=150)

right_time = tk.Label(text="--:--:--", relief="ridge", bg="#9abded")
right_time.place(x=712, y=400, width=60, height=25)


win.mainloop()
