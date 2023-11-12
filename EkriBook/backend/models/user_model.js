const mongoose = require('mongoose');
const bcrypt = require('bcryptjs');

const userSchema = mongoose.Schema({
  username: {
    type: String,
    required: true,
    unique: true
  },
  email: {
    type: String,
    required: true,
    unique: [true,"Email address already taken"]
  },
  password: {
    type: String,
    required: true
  }
}, {
  timestamps: true
});


const User = mongoose.model('User', userSchema);

module.exports = User;
