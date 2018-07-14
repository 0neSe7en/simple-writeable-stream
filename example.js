const fs = require('fs');
const SimpleStream = require('./index');

const stream = new SimpleStream();
fs.createReadStream('./test').pipe(stream);
