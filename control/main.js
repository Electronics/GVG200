var SerialPort = require("serialport");
var ATEM = require('applest-atem');

var port = new SerialPort("/dev/ttyUSB0", {
  baudRate: 115200,
  parser: SerialPort.parsers.readline('\n')
});

port.on('open', function() {
	setTimeout(bootpi, 2500);
});

function bootpi() {
port.write("!");
}

var atem = new ATEM();

var key_bus_1 = { 1:0, 2:1, 3:2, 4:3, 5:4, 6:5, 7:6, 8:7, 9:8, 10:9, 10011:12, 10010:13, 3010:14, 3020:15, 2001:16, 2002:17, 1000:18, 0:19};
var program_bus_1 = { 1:20, 2:21, 3:22, 4:23, 5:24, 6:25, 7:26, 8:27, 9:28, 10:29, 3010:34, 3020:35, 2001:36, 2002:37, 1000:38, 0:39};
var preview_bus_1 = { 1:40, 2:41, 3:42, 4:43, 5:44, 6:45, 7:46, 8:47, 9:48, 10:49, 3010:54, 3020:55, 2001:56, 2002:57, 1000:58, 0:59};
var program_bus_1_flipped = {};
var preview_bus_1_flipped = {};

function flip(obj) {
	console.log('hi')
	out = {}
	for (var key in obj) {
	    var value = obj[key];

	    out[value] = key;
	}
	return out;
}

function main() {
	program_bus_1_flipped=flip(program_bus_1);
	preview_bus_1_flipped=flip(preview_bus_1);
  atem.changeProgramInput(1); // ME1(0) 
  atem.changePreviewInput(2); // ME1(0) 
  atem.autoTransition(); // ME1(0) 
  atem.changeProgramInput(3, 1); // ME2(1) 
}


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
 
atem.on('connect', function() {
	setInterval(state2displays, 50); 
	setInterval(flash, 500);
});

port.on('open', function() {
    console.log('port is open. connecting to ATEM');
    atem.connect('10.0.1.220')  
});

var laststate;
var flashs, flashing;
var ftbflash, ftbstate;

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
		lighton(152);
		lighton(153);
	}
	if(ftbflash) {
               if(ftbstate==1) {
                        ftbstate = 0;
                        lighton(262);
                }
                else {
                        ftbstate = 1;
                        lightoff(262);
                }
	}
	else {
		lighton(262);
	}

}

var prevprog, prevprev;

var lastdsk1on, lastdsk2on, lastdsk1tie, lastdsk2tie;
var lastftbframes;

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

	var dsk1on = atem.state.video.downstreamKeyOn[0];
	var dsk2on = atem.state.video.downstreamKeyOn[1];
	var dsk1tie = atem.state.video.downstreamKeyTie[0];
	var dsk2tie = atem.state.video.downstreamKeyTie[1];

	if(lastdsk1on!=dsk1on){if(dsk1on) { lighton(154); } else {lightoff(154);}}
	if(lastdsk2on!=dsk2on){if(dsk2on) { lighton(155); } else {lightoff(155);}}

	lastdsk1on = dsk1on;
	lastdsk2on = dsk2on;
	lastdsk1tie = dsk1tie;
	lastdsk2tie = dsk2tie;

	ftbframes =  atem.state.video.ME[0].fadeToBlackFrames;

	if(ftbframes!=undefined && ftbframes!=lastftbframes) {

		display(8,ftbframes);

	}

	lastftbframes = ftbframes;

	if(atem.state.video.ME[0].fadeToBlack) { ftbflash = 1; } else { ftbflash = 0;}

}

var flipdir = 0;

port.on('data', function (data) {

	cmd = data.charAt(0);
	params = data.substr(1).split(",");

	uid = parseInt(params[0]);
	state = parseInt(params[1]);


	if(cmd=="b") {
		if(state==1) {
			parseButton(uid);
		}
	}

	if(cmd=="a") {
		if(uid==0) {
			//console.log("A1 CHANGE");			

			var state2 = state;

			if(flipdir==1) {
				state2 = 255-state;
			}

			//console.log(state2);

			atem.changeTransitionPosition((parseFloat(state2)/255)*10000);

			if(state==255) {
			flipdir = 1;
			lighton(164);
			lightoff(165);
			}
			if(state==0) {
			flipdir = 0;
			lighton(165);
			lightoff(164);
			}

		}
	}

});

function invert(num){
	if(num==0) {
		return 1;
	}

	else {
		return 0;
	}
}


var dsk1state = 0;
var dsk2state = 0;

function parseButton(uid) {

	if(uid in flip(program_bus_1)) {
		console.log("PROG_CHANGE");
		atem.changeProgramInput(program_bus_1_flipped[uid]);
	}

	if(uid in flip(preview_bus_1)) {
		console.log("PREV CHANGE");
		atem.changePreviewInput(preview_bus_1_flipped[uid]);  
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

	    case 152:
	    	atem.autoDownstreamKey(0);
	    	break;

	    case 153:
		atem.autoDownstreamKey(1);
	    	break;

	    case 262:
		atem.fadeToBlack();
	}
}


