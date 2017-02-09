var SerialPort = require("serialport");
var ATEM = require('applest-atem');

var port = new SerialPort("/dev/tty-usbserial1", {
  baudRate: 57600,
  parser: SerialPort.parsers.readline('\n')
});

var buttons = [];
var analog = [];

 
var atem = new ATEM();
atem.connect('10.0.1.220'); // Replace your ATEM switcher. address. 
 
atem.on('connect', function() {
	setTimeout(main, 10);
});
 
atem.on('stateChanged', function(err, state) {
  console.log(state); // catch the ATEM state. 
});


function main() {
  atem.changeProgramInput(1); // ME1(0) 
  atem.changePreviewInput(2); // ME1(0) 
  atem.autoTransition(); // ME1(0) 
  atem.changeProgramInput(3, 1); // ME2(1) 
}

port.on('data', function (data) {
  console.log('Data: ' + data);

  cmd = data.charAt(0);
  params = data.substr(1).split(",");
  console.log("COMMAND: "+cmd)
  console.log("PARAMS: "+params)

  if(params.length>1) {
  	  if(cmd=="b") {
	  	if(params[0]==163 && params[1]==1) {
	  		atem.autoTransition(); // ME1(0) 
	  	}
	  }
  }

});

