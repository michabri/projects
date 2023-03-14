const express = require('express');
const router = express.Router();
const productsController = require('../controllers/usersController');

const db = require('../models'); //contain the User model, which is accessible via db.User

// /nasa => GET
router.get('/', productsController.getNasaPage);

/**
 post method: gets the data and validates it. Validates if user is still logged in.
 Creating a comment in the database, sends back the comment
 */
router.post('/post', (req, res) => {
    function validationPost() {
        return !!(req.body.hasOwnProperty('date') &&
            req.body.hasOwnProperty('email') &&
            req.body.hasOwnProperty('name') &&
            req.body.hasOwnProperty('comment') &&
            Date.parse(req.body.date));
    }

    if(req.session.LoggedIn === undefined) {
        res.send(500);
        return;
    }


    if(!validationPost()) {
        res.send(500);
        return;
    }

    let u = db.Comment.build({date: req.body.date, email: req.body.email, name: req.body.name, comment: req.body.comment});
    u.save()
        .then((comment) => res.json(comment))
        .catch((err) => {
            res.render('nasa', {
                pageTitle: 'nasa',
                path: '/nasa',
                error: {hasError: true, error: err.toString()},
            });
        })
});
// /nasa/comments => GET
router.get('/comments', (req, res) => {
    if(req.session.LoggedIn === undefined) {
        res.send(500);
        return;
    }
    return db.Comment.findAll()
        .then((comments) => res.send(comments))
        .catch((err) => {
            console.log('There was an error querying contacts', JSON.stringify(err))
            err.error = 1; // some error code for client side
            return res.send(err)
        });
});

/**
 * get method, getting a single resource - the id(date) of the picture,
 *  sends back an array with the data of the comments of the picture according to the id we got.
 *  Validates if the parameter we got is a date.
 */
router.get('/nasa/:id', (req, res) => {
    if(req.session.LoggedIn === undefined) {
        res.send(500);
        return;
    }
    if(!Date.parse(req.params.id)) {
        res.send(500);
        return;
    }
    const date_id = req.params.id;
    let array = [];
    db.Comment.findAll()
        .then(function (comments) {
            comments.forEach((item) => {
                if (item.date === date_id) {
                    array.push(item);
                }
            })
            res.json(array);
        })
});
/**
 Deleting the comment
 Gets the counter of the comment,
 validates if the dataBase contains the id,
 and validates if the comment was deleted from dataBase
 */
router.delete('/nasa/:id', (req, res) => {
    const id = parseInt(req.params.id);
    if(req.session.LoggedIn === undefined) {
        res.send(500);
        return;
    }
    if(!id) {
        res.send(500);
        return;
    }
    return db.Comment.findAll()
        .then(function(comments) {
            comments.forEach((item) => {
              if(item.id === id)
                  item.destroy({ force: true })
            })
        })
        .then(() => res.send({ id }))
        .catch((err) => {
            console.log('***Error deleting comment', JSON.stringify(err))
            res.status(400).send(err)
        })
});

module.exports = router;