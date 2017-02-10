var SerialPort = require("serialport");
var ATEM = require('applest-atem');

var port = new SerialPort("/dev/ttyUSB0", {
  baudRate: 115200,
  parser: SerialPort.parsers.readline('\n')
});

var buttons = [];
var analog = [];

function pad(num, size) {
    var s = num+"";
    while (s.length < size) s = "0" + s;
    return s;
}

 
var atem = new ATEM();
 
atem.on('connect', function() {
	setTimeout(main,10);
	setInterval(senddisplays,500);
});

function connectatem() {

atem.connect('10.0.1.220')

}
 

var d2 = 000;

atem.on('stateChanged', function(err, state) {
  //console.log(state); // catch the ATEM state.
  fc = state.video.ME[0].transitionFrameCount;
   if(fc!=undefined) {
	d2 = pad(fc, 3);	
  }
});


port.on('open', function() {
    console.log('port is open. connecting to ATEM');
    setTimeout(connectatem,500);
});

function senddisplays() {
	port.write("d2,"+d2);
	console.log("d2,"+d2);
}


function main() {
  atem.changeProgramInput(1); // ME1(0) 
  atem.changePreviewInput(2); // ME1(0) 
  atem.autoTransition(); // ME1(0) 
  atem.changeProgramInput(3, 1); // ME2(1) 
}


port.on('data', function (data) {
  //console.log('Data: ' + data);

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
			atem.autoTransition();
	    		break;
    		case 163:
			atem.cutTransition();
	        	break;
    		default:
	        	break;
	}
}

