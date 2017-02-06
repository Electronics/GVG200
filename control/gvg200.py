import serial
import threading
from time import sleep

s = serial.Serial("/dev/ttyAMA0", 115200)

analog = {}
button = {}

MENU_1 = 264
MENU_2 = 265
MENU_3 = 266
MENU_4 = 267
MENU_5 = 268

ENABLE_EDITOR = 329
ENABLE_GPI	= 330
ENABLE_PERIPH = 331
ENABLE_EXTRA = 332

def setlight(addr, state):
	s.write("l"+str(addr)+","+str(state)+"\x00")

def setdisplay(addr, val):
	s.write("d"+str(addr)+","+str(val)+"\x00")
	

def recv():
	cmd = s.readline()

	#Analogue value reading
	if(cmd[:1]=="a"):
		p = cmd[1:].split(",")
		#Puts it into the analog dict as ADDR:VAL
		analog.update({int(p[0]):int(p[1])})
		return

	if(cmd[:1]=="b"):
		p = cmd[1:].split(",")
		#Puts it into the button dict as ADDR:VAL
		button.update({int(p[0]):int(p[1])})

		if(mode=="light_test"):
			s.write("l"+cmd[1:]+"\x00")
			return


def receive_thread():
	while True:
		recv()

def operation_thread():
	setdisplay(0, "GVG-200 Production Control")
	while True:
		setlight(ENABLE_EDITOR, 1)
		sleep(1)
		setlight(ENABLE_EDITOR, 0)
		sleep(1)


rthread = threading.Thread(target=receive_thread)
rthread.start()