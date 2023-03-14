// note that this controller returns HTML only!
// it sometimes also redirects to other routes.
// if it was a REST API, it would return JSON.

const keys = ['keyboard cat'];
const Cookies = require('cookies');
const db = require('../models');
const bcrypt = require("bcrypt")
let email_tmp = ""; //while the user has registered the email but not the password yet

/**
 * displays the home page.
 * @param req
 * @param res
 * @param next
 */
exports.getLoginPage = (req, res, next) => {
  if(req.session.LoggedIn)
    res.redirect('/nasa');
  else
    res.render('loginPage', {
      pageTitle: 'loginPage',
      path: '/',
      error: {hasError: false, error: null},
    });
};

exports.getLogout =(req, res, next) => {
    req.session.LoggedIn = false;
    res.render('loginPage', {
      pageTitle: 'loginPage',
      path: '/',
      error: {hasError: true, error: "you are logged out, session is over"},
    });
};
/**
 * displays the register page that includes a form.
 * @param req
 * @param res
 * @param next
 */
exports.getRegisterPage = (req, res, next) => {
  const cookies = new Cookies(req, res, { keys: keys })
  const lastVisit = cookies.get('LastVisit', { signed: true });
  let data = ["", "", ""];
  let hasData = lastVisit;
  if(hasData) {
    data = lastVisit.split('/');
    email_tmp = "";
  }
  res.render('register', {
    pageTitle: 'register',
    path: '/users/register',
    error: {hasError : false, error : null},
    data: {hasData : hasData, data: {email : data[0], first_name : data[1], last_name : data[2]}}
  });
};
/**
 * displays the passwords page that includes a form.
 * @param req
 * @param res
 * @param next
 */
exports.getPasswordsPage = (req, res, next) => {
  const cookies = new Cookies(req, res, { keys: keys })
  const lastVisit = cookies.get('LastVisit', { signed: true });
  if(!lastVisit)
    res.redirect('register');
  else {
    res.render('register-passwords', {
      pageTitle: 'register-passwords',
      path: '/users/register-passwords',
      error: {hasError: false, error: null},
    });
  }
};
/**
 * displays the nasa page that includes the pictures and the comments.
 * @param req
 * @param res
 * @param next
 */
exports.getNasaPage = (req, res, next) => {
  if(!req.session.LoggedIn)
    res.redirect('/');
  else
    res.render('nasa', {
      pageTitle: 'nasa',
      path: '/nasa',
      name: req.session.name,
      email: req.session.email
    });
}
/**
 * handles the post request from the login page.
 * redirects to the nasa page
 * @param req
 * @param res
 * @param next
 */
exports.postLoginPage = (req, res, next) => {
  req.session.LoggedIn = false;
  db.User.findAll()
      .then(function(users) {
        if(users.find(item => item.email === req.body.email.trim())) {
          users.forEach(function (item) {
            if (item.email === req.body.email.trim()) {
              bcrypt.compare(req.body.password, item.password, function (err, result) {
                if (result) {
                  req.session.LoggedIn = true;
                  req.session.name = `${item.firstName} ${item.lastName}`;
                  req.session.email = item.email
                  res.redirect('nasa');
                }
                else
                  renderLoginPage(res);
              });
            }
          })
        }
        else
            renderLoginPage(res);
        })
      .catch((err) => {
        res.render('loginPage', {
          pageTitle: 'loginPage',
          path: '/',
          error: {hasError: true, error: err.toString()},
        })
      })
}
/**
 * handles the post request from the register page.
 * redirects to the passwords page.
 * @param req
 * @param res
 * @param next
 */
exports.postRegisterEmail = (req, res, next) => {
  const cookies = new Cookies(req, res, { keys: keys })
  db.User.findAll()
      .then(function(users) {
        let found = users.find(item => item.email === req.body.email.trim())
        if(found || email_tmp === req.body.email.trim())
          throw (new Error("email already exists, please try again"));
            })
      .then(() => {
          cookies.set(
              'LastVisit',
              `${req.body.email.trim().toLowerCase()}/${req.body.first_name.trim()}/${req.body.last_name.trim()}`,
              {signed: true, maxAge: 30 * 1000})
          email_tmp = req.body.email.trim();
          res.redirect('register-passwords');
          })
      .catch((err) => {
        res.render('register', {
          pageTitle: 'register',
          path: '/users/register',
          error: {hasError: true, error: err},
          data: {hasData: false, data: {email: "", first_name: "", last_name: ""}}
        })
      });
};
/**
 * handles the post request from the passwords page. Saves the user to the DB.
 * @param req
 * @param res
 * @param next
 */
exports.postRegisterPasswords = (req, res, next) => {
  const cookies = new Cookies(req, res, { keys: keys })
  const lastVisit = cookies.get('LastVisit', { signed: true })
  if(!lastVisit) {
    //EXPIRED
    email_tmp = "";
    res.render('register', {
      pageTitle: 'register',
      path: '/users/register',
      error: {hasError: true, error: "Registration process has expired, please try again"},
      data: {hasData : false, data : {email : "", first_name : "", last_name : ""}}
    });
  }
  else if (req.body.password !== req.body.confirm_password) {
      res.render('register-passwords', {
        pageTitle: 'register-passwords',
        path: '/users/register-passwords',
        error: {hasError: true, error: "passwords do not match, please try again"},
      })
    }
  else {
    email_tmp = "";
    let data = lastVisit.split('/');
    cookies.set('LastVisit', '', {signed : true, maxAge: 0});
    bcrypt.genSalt(10, (err, salt) => {
      bcrypt.hash(req.body.password, salt, function(err, hash) {
        let u = db.User.build({ firstName: data[1], lastName: data[2], email: data[0], password:  hash});
        return u.save()
            .then((users) =>
              res.render('loginPage', {
              pageTitle: 'loginPage',
              path: '/',
              error: {hasError: true, error: "Registration successful, you can now login"},
            }))
            .catch((err) => {
              res.render('register', {
                pageTitle: 'register',
                path: '/users/register',
                error: {hasError: true, error: err.toString()},
                data: {hasData: false, data: {email: "", first_name: "", last_name: ""}},
              })
            })
      });
     })
  }
};

function renderLoginPage(res) {
  res.render('loginPage', {
    pageTitle: 'loginPage',
    path: '/',
    error: {hasError: true, error: "email or password is incorrect, please try again"},
  })
}