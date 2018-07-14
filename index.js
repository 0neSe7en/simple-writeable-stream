const { Writable } = require('stream');
const stream = require('bindings')('stream');

module.exports = class SimpleStream extends Writable {
  constructor(name, streamOption) {
    super(streamOption);
    this.name = name;
  }

  _write(buf, encoding, next) {
    stream.write(buf);
    next();
  }
};
