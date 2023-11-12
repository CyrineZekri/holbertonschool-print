const express = require('express');
const User = require('../models/user_model');
const router = express.Router();

// Register a new user
router.post('/register', async (req, res) => {
    const { username, email, password } = req.body;

    const userExists = await User.findOne({ email });

    if (userExists) {
        res.status(400).send('User already exists');
        return;
    }

    const user = await User.create({
        username,
        email,
        password
    });

    if (user) {
        res.status(201).json({
            _id: user._id,
            username: user.username,
            email: user.email
        });
    } else {
        res.status(400).send('Invalid user data');
    }
});

// Get user details
router.get('/user/:userId', async (req, res) => {
    try {
        const user = await User.findById(req.params.userId);

        if (!user) {
            res.status(404).send('User not found');
            return;
        }

        res.json({
            _id: user._id,
            username: user.username,
            email: user.email
        });
    } catch (error) {
        res.status(500).send('Server error');
    }
});

module.exports = UserRoutes;
