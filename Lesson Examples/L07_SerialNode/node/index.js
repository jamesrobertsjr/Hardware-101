const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');

const port = new SerialPort({
    path: '/dev/tty.SLAB_USBtoUART',
    baudRate: 9600
});
const parser = port.pipe(new ReadlineParser("\n"));

// Confirm serial port is open
port.on('open', () => {
  console.log('Connected to Arduino');
});

// Read parsed serial data
parser.on('data', data => {
  console.log(data);
  port.write('Hello from Node!');
});