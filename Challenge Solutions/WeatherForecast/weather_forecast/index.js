const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');
const https = require('https');
var HttpsProxyAgent = require('https-proxy-agent');

var proxy = process.env.http_proxy;
var agent = new HttpsProxyAgent(proxy);

const lat = 33.15, long = -96.82;
const API_KEY = '';

const options = {
    hostname: 'api.openweathermap.org',
    path: `/data/2.5/weather?lat=${lat}&lon=${long}&appid=${API_KEY}&units=imperial`,
    method: 'GET',
    agent: agent
}

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
parser.on('data', inData => {
    console.log('Data received');
    
    https.request(options, (res) => {
        let data = ''
        
        res.on('data', (chunk) => {
            data += chunk;
        });
        
        // Ending the response 
        res.on('end', () => {
            const wData = JSON.parse(data);
            let outData = "Temp: " + wData.main.temp;
            outData += "\n" + wData.weather[0].main;
            outData += "\nHigh: " + wData.main.temp_max;
            outData += "\nLow: " + wData.main.temp_min;
            port.write(outData)
        });
       
    }).on("error", (err) => {
        console.log("Error: ", err)
    }).end()
  
});