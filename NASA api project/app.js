let express = require('express');
let path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
var createError = require('http-errors');

let loginRouter = require('./routes/loginPage');
let registerRouter = require('./routes/register');
let commentsRouter = require('./routes/commentsApi');

let app = express();

// express views folder and engine
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

app.use(logger('dev'));

/// built in express middleware parses incoming requests with JSON
app.use(express.json());

// extended false means you can not post "nested object" {a {b:c}}
// parses incoming requests with urlencoded
app.use(express.urlencoded({ extended: false }));

// COOKIES
app.use(cookieParser());

// make public folder visible for static files (client side javascript)
app.use(express.static(path.join(__dirname, 'public')));

var Sequelize = require('sequelize')
var session = require('express-session');
var SequelizeStore = require('connect-session-sequelize')(session.Store);

var sequelize = new Sequelize({
  "dialect": "sqlite",
  "storage": "./session.sqlite"
});
var myStore = new SequelizeStore({
  db: sequelize
})

app.use(session({
  secret:"somesecretkey",
  store:myStore,
  resave: false, // Force save of session for each request
  saveUninitialized: false, // Save a session that is new, but has not been modified
  cookie: {maxAge: 10*60*1000 } // milliseconds! 10 min
}));

myStore.sync();

// OUR ROUTE!!
app.use(loginRouter);
app.use('/users', registerRouter);
app.use('/nasa', commentsRouter);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error', {
    pageTitle: 'error',
        path: '/error',
        error: err
  })
  // use a default error page error.ejs
});

module.exports = app;
