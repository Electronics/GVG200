import serial
import threading
from time import sleep
import sys
from atem import *

a = Atem()
a.connectToSwitcher (('10.0.1.220',9910))

s = serial.Serial("/dev/ttyUSB0", 115200)

analog = [0]*500
button = [0]*500

MENU_1 = 264
MENU_2 = 265
MENU_3 = 266
MENU_4 = 267
MENU_5 = 268

ENABLE_EDITOR = 329
ENABLE_GPI	= 330
ENABLE_PERIPH = 331
ENABLE_EXTRA = 332
ME1_TRANS_CUT = 163


mode = ""

def setlight(addr, state):
	s.write("l"+str(addr)+","+str(state)+"\x00")

def setdisplay(addr, val):
	s.write("d"+str(addr)+","+str(val)+"\x00")
	

def recv():
	cmd = s.readline()
	global mode
	#Analogue value reading
	if(cmd[:1]=="a"):
		p = cmd[1:].split(",")
		#Puts it into the analog dict as ADDR:VAL
		analog[int(p[0])] = int(p[1])
		return

	if(cmd[:1]=="b"):
		p = cmd[1:].split(",")
		#Puts it into the button dict as ADDR:VAL
		button[int(p[0])] = int(p[1])

		if(mode=="light_test"):
			s.write("l"+cmd[1:]+"\x00")
			return


def receive_thread():
	while True:
		try:
			recv()
		except:
			print "Serial Error occurred. Skipping"
def operation_thread():
	print "Setting operation"
	global mode
	sleep(2)
	setdisplay(0, "GVG-200 Production Control"+"\n"+"Buttons"+"   Rave " + "  Analog")
	while True:
#		setlight(ENABLE_EDITOR, 1)
#		sleep(1)
#		setlight(ENABLE_EDITOR, 0)
#		sleep(1)
		if(button[MENU_1]==1):
			print "BUTTONS MODE"
			if(mode != "light_test"):
				mode = "light_test"
				button[MENU_1]=0
				setlight(MENU_1, 1)
			else:
				mode = ""
				setlight(MENU_1, 0) 
		if(button[MENU_2]==1):
			print "RAVE MODE"
                        if(mode != "rave"):
                                mode = "rave"
                                button[MENU_2]=0
                                setlight(MENU_2, 1)
                        else:
                                mode = ""
                                setlight(MENU_2, 0)

		if(button[MENU_3]==1):
			print "Analog Calibrate"
			s.write("~")
			button[MENU_3]=0

		if(button[ME1_TRANS_CUT]==1):
			button[ME1_TRANS_CUT]=0
			print "CUT"
			a.sendCommand ("DCut", "\x00\x00\x00\x00"); 



rthread = threading.Thread(target=receive_thread)
rthread.daemon = True
rthread.start()

othread = threading.Thread(target=operation_thread)
othread.daemon = True
othread.start()

while True:
	print "Main Thread"
	raw_input("Press enter to exit\n")
	sys.exit()
