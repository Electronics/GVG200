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
	setInterval(state2displays, 10); 
	setInterval(flash, 1000);
});

port.on('open', function() {
    console.log('port is open. connecting to ATEM');
    atem.connect('10.0.1.220')  
});

var laststate;
var flashs, flashing;

function flash() {
	if(flashing) {
	if(flashs==1) {
	flashs = 0;
	port.write("l162,1,"+Buffer.from("00", "hex")); 
	}
	else {
	flashs = 1;
	port.write("l162,0,"+Buffer.from("00", "hex")); 
	}
	}
	else {
port.write("l162,1,"+Buffer.from("00", "hex"));
port.write("l163,1,"+Buffer.from("00", "hex"));
}
}

var prevprog, prevprev;

function state2displays() {
	state = atem.state.video.ME[0].transitionFrameCount;
	pos = atem.state.video.ME[0].transitionPosition;
	if(pos>0) {
		flashing = 1;
	}
	else {
	flashing = 0;
	}
	if(state!=undefined && state!=laststate) {
		padded=pad(state,3);
		laststate = state;
		port.write("d2,"+padded+Buffer.from("00", "hex"));
	}

	prog = atem.state.video.ME[0].programInput;
	prev = atem.state.video.ME[0].previewInput;
	
	if(prog!=prevprog) {
		port.write("l,"+(prevprog+19)+Buffer.from("00", "hex"));
		port.write("l,"+(prog+19)+",1"+Buffer.from("00", "hex")); 
	} 

        if(prev!=prevprev) {
                port.write("l,"+(prevprev+39)+",0"+Buffer.from("00", "hex"));
                port.write("l,"+(prev+39)+",1"+Buffer.from("00", "hex"));
        }

	prevprog = prog;
	prevprev = prev;
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

	if(uid>=20 && uid<40) {
		console.log("PROG_CHANGE");
		atem.changeProgramInput(uid-19);
	}

	if(uid>=40 && uid<60) {
		console.log("PREV CHANGE");
		atem.changePreviewInput(uid-39);  
	}

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


