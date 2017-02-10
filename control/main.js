var ATEM = require('applest-atem');

 
var atem = new ATEM();

atem.on('connect', function() {
	setTimeout(main,10);
});


atem.on('stateChanged', function(err, state) {
  //console.log(state); // catch the ATEM state.
  client.write(JSON.stringify(state));
});


function main() {
  atem.changeProgramInput(1); // ME1(0) 
  atem.changePreviewInput(2); // ME1(0) 
  atem.autoTransition(); // ME1(0) 
  atem.changeProgramInput(3, 1); // ME2(1) 
}


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

var net = require('net');

var client = new net.Socket();
client.connect(9999, '127.0.0.1', function() {
	console.log('Connected');
	atem.connect("10.0.1.220");	
});

client.on('data', function(data) {

  data = data.toString();

	console.log(data);
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

client.on('close', function() {
	console.log('Connection closed');
});
