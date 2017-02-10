var ATEM = require('applest-atem');

var atem = new ATEM();
atem.connect('10.0.1.220'); // Replace your ATEM switcher. address.

atem.on('connect', function() {
  atem.changeProgramInput(1); // ME1(0)
  atem.changePreviewInput(2); // ME1(0)
  atem.autoTransition(); // ME1(0)
  atem.changeProgramInput(3, 1); // ME2(1)
});

atem.on('stateChanged', function(err, state) {
  console.log(state); // catch the ATEM state.
});
console.log(atem.state); // or use this.
