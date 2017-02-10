// From https://gist.github.com/creationix/707146
net = require('net');

var ATEM = require('applest-atem');
var atem = new ATEM();
atem.connect('10.0.1.220')

// Keep track of the chat clients
var clients = [];

var n = 20;

// Start a TCP Server
net.createServer(function (socket) {

  // Identify this client
  socket.name = socket.remoteAddress + ":" + socket.remotePort 

  // Put this new client in the list
  clients.push(socket);

  // Handle incoming messages from clients.
  socket.on('data', function (data) {
    to_eval = data.toString();
    try {
      out = eval(to_eval);
    } catch (err) {
      out = "ERR";
    }
    
    socket.write(JSON.stringify(out));
  });

  // Remove the client from the list when it leaves
  socket.on('end', function () {
    clients.splice(clients.indexOf(socket), 1);
    broadcast(socket.name + " left the chat.\n");
  });
  

}).listen(5000);

// Put a friendly message on the terminal of the server.
console.log("Super secure server running at port 5000\n");