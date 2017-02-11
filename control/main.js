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

function lighton(n) {
	port.write("l"+n+",1"+Buffer.from("00", "hex")); 
}

function lightoff(n) {
	port.write("l"+n+",0"+Buffer.from("00", "hex")); 
}

function maindisplay(data) {
	port.write("d1,"+data+Buffer.from("00", "hex")); 
}

function display(num, data) {
	port.write("d"+num+","+pad(data,3)+Buffer.from("00", "hex")); 

}


var key_bus_1 = { 1:0, 2:1, 3:2, 4:3, 5:4, 6:5, 7:6, 8:7, 9:8, 10:9, 10011:12, 10010:13, 3010:14, 3020:15, 2001:16, 2002:17, 1000:18, 0:19};
var program_bus_1 = { 1:20, 2:21, 3:22, 4:23, 5:24, 6:25, 7:26, 8:27, 9:28, 10:29, 3010:34, 3020:35, 2001:36, 2002:37, 1000:38, 0:39};
var preview_bus_1 = { 1:40, 2:41, 3:42, 4:43, 5:44, 6:45, 7:46, 8:47, 9:48, 10:49, 3010:54, 3020:55, 2001:56, 2002:57, 1000:58, 0:59};

function flip(obj) {
	out = {}
	for (var key in obj) {
	    var value = obj[key];

	    out[value] = key;
	}
	return out;
}


var atem = new ATEM();
 
atem.on('connect', function() {
	setInterval(state2displays, 40); 
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
			lighton(162);
		}
		else {
			flashs = 1;
			lightoff(162); 
		}
	}
	else {
		lighton(162);
		lighton(163);
	}
}

var prevprog, prevprev;

function state2displays() {
	state = atem.state.video.ME[0].transitionFrameCount;
	pos = atem.state.video.ME[0].transitionPosition;

	flashing = pos>0 ? 1 : 0;

	if(state!=undefined && state!=laststate) {
		display(2,state);
	}

	prog = atem.state.video.ME[0].programInput;
	prev = atem.state.video.ME[0].previewInput;
	
	if(prog!=prevprog) {
		lightoff(program_bus_1[prevprog]);
		lighton(program_bus_1[prog]);
	} 

    if(prev!=prevprev) {
		lightoff(preview_bus_1[prevprev]);
		lighton(preview_bus_1[prev]);
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

	console.log(data);

	if(cmd=="b") {
		if(state==1) {
			parseButton(uid);
		}
	}

});


function parseButton(uid) {

	if(uid in flip(program_bus_1)) {
		console.log("PROG_CHANGE");
		atem.changeProgramInput(flip(program_bus_1)[uid]);
	}

	if(uid in flip(preview_bus_1)) {
		console.log("PREV CHANGE");
		atem.changePreviewInput(flip(preview_bus_1)[uid]);  
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


