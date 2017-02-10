import serial
import threading

from time import sleep

s = serial.Serial("/dev/ttyUSB0", 115200);

import socket
import sys

HOST, PORT = "localhost", 9999
data = " ".join(sys.argv[1:])

# Create a socket (SOCK_STREAM means a TCP socket)
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.connect((HOST, PORT))

def receive_thread():
	received = sock.recv(2048)
	print received


def send_thread():
	dat = s.readline()
	sock.sendall(dat)


rthread = threading.Thread(target=receive_thread)
rthread.daemon = True
rthread.start()

othread = threading.Thread(target=send_thread)
othread.daemon = True
othread.start()

while True:
	sleep(1)
