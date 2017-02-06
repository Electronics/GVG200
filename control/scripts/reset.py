import serial

s = serial.Serial("/dev/ttyAMA0", 115200)

s.write("!")
