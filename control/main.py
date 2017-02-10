import serial
import threading

from time import sleep

ser = serial.Serial("/dev/ttyUSB0", 115200);


import socket

HOST = ''                 # Symbolic name meaning all available interfaces
PORT = 9999              # Arbitrary non-privileged port
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(1)

conn, addr = s.accept()
print 'Connected by', addr

def receive_thread():
	while(True):
		data = conn.recv(2048)
		print data

def send_thread():
	while(True):
		dat = ser.readline()
		conn.sendall(dat)

rthread = threading.Thread(target=receive_thread)
rthread.daemon = True
rthread.start()

othread = threading.Thread(target=send_thread)
othread.daemon = True
othread.start()

while True:
	sleep(1)
