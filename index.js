const { Writable } = require('stream');
const stream = require('bindings')('stream');

module.exports = class SimpleStream extends Writable {
  _write(buf, encoding, next) {
    stream.write(buf);
    next();
  }
};
