const mongoose = require('mongoose');

const bookSchema = mongoose.Schema({
    title: {
        type: String,
        required: true,
        unique: true 
    },
    author: {
        type: String,
        required: true
    },
    isRented: {
        type: Boolean,
        default: false
    },
    rentUntil: {
        type: Date
    },
    rentPrice: {
        type: Number,
        required: true
    }
}, { timestamps: true });

module.exports = mongoose.model('Book', bookSchema);
