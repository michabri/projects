const express = require('express');

const productsController = require('../controllers/usersController');

const router = express.Router();

// / => GET
router.get('/', productsController.getLoginPage);
// / => POST
router.post('/', productsController.postLoginPage);
// /logout => GET
router.get('/logout',productsController.getLogout);


module.exports = router;