from atem import *

a = Atem()
a.connectToSwitcher (('10.0.1.220',9910))

a.waitForPacket()
a.waitForPacket()
a.waitForPacket()
a.waitForPacket()
a.waitForPacket()
a.waitForPacket()
a.waitForPacket()
a.sendCommand ("DCut", "\x00\x00\x00\x00");
a.waitForPacket()

while (True):   
	raw_input("go?")
	a.sendCommand ("DCut", "\x00\x00\x00\x00");
	a.waitForPacket()


