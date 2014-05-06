#!/usr/bin/env node

//-----------------------
//I send the npm modules because the .rar was too small, and it didn't let me send it otherwise
//-------------------------

if ((process.version.split('.')[1]|0) < 10) {
	console.log('Please, upgrade your node version to 0.10+');
	process.exit();
}

var net = require('net');
var util = require('util');
var crypto = require('crypto');

var options = {
	'port': 6969,
	'host': '54.83.207.90',
}

var KEYPHRASE = 'BlueBellPsychologicalFoxIsActive';

var dh, dh2, secret, state = 0;

process.stdin.resume();
process.stdin.setEncoding('utf8');

var socket;
 
process.stdin.once('data', function (chunk) {
	var str = chunk.substring(0,chunk.length);
	
	KEYPHRASE = str;

	//console.dir(str);

	socket = net.connect(options, function() {
		//socket.write('hello?');
		//state++;
	});

	var data2;
	var data3;
	var data4;
	var data5;
	var secret2;

	socket.on('data', function(data) {

		//console.dir(data);

		data = data.toString().trim().split('|');

		//console.dir(data);
		//console.dir(state);

		if (state==0) {
			socket.write('hello?\n');
			state++;
		}
		else if (state==1) {
			socket.write('hello!\n');
			state++;
		}
		else if (state==2) {
			dh = crypto.createDiffieHellman(256);
			dh.generateKeys();
			socket.write(util.format('key|%s|%s\n', dh.getPrime('hex'), dh.getPublicKey('hex'))); //My key
			//socket.write('key|' + data[1] + '|' + data[2] + '\n')
			data2 = data; //CLIENT key
			state++;
			//console.dir(util.format('key|%s|%s\n', dh.getPrime('hex'), dh.getPublicKey('hex')));
		}
		else if (state==3) {
			//console.dir(data2);
			dh2 = crypto.createDiffieHellman(data2[1], 'hex');
			dh2.generateKeys();
			secret2 = dh.computeSecret(data2[2], 'hex');
			//socket.write(util.format('key|%s\n', dh.getPublicKey('hex'))); //Response to client from his key
			socket.write('key|' + data[1] + '\n');
			data3 = data; //Response from server for my key
			//secret2 = secret;
			state++;
		}
		else if (state==4 && data.length==2) {
			//console.dir(data);
			//console.dir(data3[1]);
			secret = dh.computeSecret(data3[1], 'hex');
			var cipher = crypto.createCipheriv('aes-256-ecb', secret, '');
			var keyphrase = cipher.update(KEYPHRASE, 'utf8', 'hex') + cipher.final('hex');
			socket.write(util.format('keyphrase|%s\n', keyphrase)); // Send server second message
			//socket.write('keyphrase|' + data[1] + '\n');
			data4 = data;
			state++;
		}
		else if (state==5 && data.length==2) {
			//console.dir("FINAL");
			//console.dir(data);
			//console.dir(data[1])
			var decipher = crypto.createDecipheriv('aes-256-ecb', secret, '');
		 	var message = decipher.update(data[1], 'hex', 'utf8') + decipher.final('utf8');
		 	console.log(message);
		 	socket.end();
		 	process.exit();
		 }


		// if (state == 1 && data[0] == 'SERVER->CLIENT:hello!') {
		// 	socket.write('hello!\n');
		// 	//dh = crypto.createDiffieHellman(256);
		// 	//dh.generateKeys();
		// 	//socket.write(util.format('key|%s|%s\n', dh.getPrime('hex'), dh.getPublicKey('hex')));
		// 	//console.dir(util.format('key|%s|%s\n', dh.getPrime('hex'), dh.getPublicKey('hex')));
		// 	state++;
		// } else if (state == 2 && data[0] == 'key') {
		// 	secret = dh.computeSecret(data[1], 'hex');
		// 	var cipher = crypto.createCipheriv('aes-256-ecb', secret, '');
		// 	var keyphrase = cipher.update(KEYPHRASE, 'utf8', 'hex') + cipher.final('hex');
		// 	socket.write(util.format('keyphrase|%s\n', keyphrase));
		// 	state++;
		// } else if (state == 3 && data[0] == 'result') {
		// 	var decipher = crypto.createDecipheriv('aes-256-ecb', secret, '');
		// 	var message = decipher.update(data[1], 'hex', 'utf8') + decipher.final('utf8');
		// 	console.log(message);
		// 	socket.end();
		// } else {
		// 	console.log('Error');
		// 	//socket.end();
		// }

	});
	

});


