const express = require('express');

// load the controllers
const usersController = require('../controllers/usersController');
const db = require("../models");

const router = express.Router();

// /users/register => GET
router.get('/register', usersController.getRegisterPage);
// /users/register => POST
router.post('/register', usersController.postRegisterEmail);
// /users/register-passwords => GET
router.get('/register-passwords', usersController.getPasswordsPage);
// /users/register-passwords => POST
router.post('/register-passwords', usersController.postRegisterPasswords);
// /users/users => GET
router.get('/users', (req, res) => {
    return db.User.findAll()
        .then((users) => res.send(users))
        .catch((err) => {
            console.log('There was an error querying contacts', JSON.stringify(err))
            err.error = 1; // some error code for client side
            return res.send(err)
        });
});

module.exports = router;
