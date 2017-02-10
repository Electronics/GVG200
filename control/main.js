var SerialPort = require("serialport");
var ATEM = require('applest-atem');

var port = new SerialPort("/dev/ttyUSB0", {
  baudRate: 115200,
  parser: SerialPort.parsers.readline('\n')
});


function pad(num, size) {
    var s = num+"";
    while (s.length < size) s = "0" + s;
    return s;
}

 
var atem = new ATEM();
 
atem.on('connect', function() {
	setInterval(state2displays, 40); 
});

port.on('open', function() {
    console.log('port is open. connecting to ATEM');
    atem.connect('10.0.1.220')  
});

function state2displays() {
	state = atem.state.video.ME[0].transitionFrameCount;
	if(state!=undefined) {
		padded=pad(state,3);
		port.write("d2,"+padded);
		port.write([0x00]);
	}
}


function main() {
  atem.changeProgramInput(1); // ME1(0) 
  atem.changePreviewInput(2); // ME1(0) 
  atem.autoTransition(); // ME1(0) 
  atem.changeProgramInput(3, 1); // ME2(1) 
}


port.on('data', function (data) {

  cmd = data.charAt(0);
  params = data.substr(1).split(",");
  
  uid = parseInt(params[0]);
  state = parseInt(params[1]);
  //console.log("COMMAND: "+cmd)
  //console.log("PARAMS: "+params)

if(cmd=="b") {
	if(state==1) {
		parseButton(uid);
	}
}

});


function parseButton(uid) {

	switch(uid) {
		case 162:
			console.log("TRANSITION");
			atem.autoTransition();
	    		break;
    		case 163:
			console.log("CUT");
			atem.cutTransition();
	        	break;
    		default:
	        	break;
	}
}


