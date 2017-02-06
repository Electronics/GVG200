import serial

s = serial.Serial("/dev/ttyUSB0", 115200)


while True:
	dat = s.readline()
	c = dat[0]

	dat2 = dat.split(",")

	if(c=="b"):
		print dat
		s.write("l"+dat[1:]+"\x00")
		print ("l"+dat[1:]+"\x00")		
