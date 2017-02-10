var ATEM = require('applest-atem');

var atem = new ATEM();
atem.connect('10.0.1.220'); // Replace your ATEM switcher. address.

atem.on('connect', function() {
	console.log(JSON.stringify(atem.state)); // catch the ATEM state. 
});


