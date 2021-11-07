const express = require('express');
const path = require('path');
const cookieParser = require('cookie-parser');
const bodyParser = require('body-parser');
const exphbs = require('express-handlebars');
const expressValidator = require('express-validator');
const flash = require('connect-flash');
const session = require('express-session');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;
const mongo = require('mongodb');
const mongoose = require('mongoose');
const request = require('request');

mongoose.Promise = global.Promise;

mongoose.connect('mongodb://localhost/dashboard', {
	useMongoClient: true
});

var db = mongoose.connection;

const routes = require('./routes/index');
const users = require('./routes/users');

const app = express();
app.set('views', path.join(__dirname, 'views'));
app.engine('handlebars', exphbs({defaultLayout:'layout'}));
app.set('view engine', 'handlebars');

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cookieParser());

app.use(express.static(path.join(__dirname, 'public')));

app.use(session({
	secret: 'dashboard',
    saveUninitialized: true,
    resave: true
}));


app.use(passport.initialize());
app.use(passport.session());

app.use(expressValidator({
  errorFormatter: function(param, msg, value) {
      var namespace = param.split('.')
      , root    = namespace.shift()
      , formParam = root;

    while(namespace.length) {
      formParam += '[' + namespace.shift() + ']';
    }
    return {
      param : formParam,
      msg   : msg,
      value : value
    };
  }
}));

app.use(flash());
app.use(function (req, res, next) {
  res.locals.success_msg = req.flash('success_msg');
  res.locals.error_msg = req.flash('error_msg');
  res.locals.error = req.flash('error');
  res.locals.user = req.user || null;
  next();
});

app.use('/', routes);
app.use('/users', users);

app.get('/menu', (req, res) => {
   res.sendFile( __dirname + "/" + "/views/menu.html" );
})

app.get('/map', (req, res) => {
   res.sendFile( __dirname + "/" + "/views/map.html" );
})

const apiKey = 'dae18fa95eb8014c8221c59b485d0cfe';

app.get('/weather', function (req, res) {
    app.use(bodyParser.urlencoded({ extended: true }));
    app.set('view engine', 'ejs')
    res.render('weather', {weather: null, error: null});
})

app.post('/weather', function (req, res) {
  let city = req.body.city;
  let url = `http://api.openweathermap.org/data/2.5/weather?q=${city}&units=metric&appid=${apiKey}`

  request(url, function (err, response, body) {
    if(err){
      res.render('weather', {weather: null, error: 'Error, please try again'});
    } else {
      let weather = JSON.parse(body)
      if(weather.main == undefined){
        res.render('weather', {weather: null, error: 'Error, please try again'});
      } else {
        let weatherText = `Il fait ${weather.main.temp} degre a ${weather.name}`;
          res.render('weather', {weather: weatherText, error: null});
      }
	app.set('view engine', 'handlebars');
	app.use(bodyParser.urlencoded({ extended: false }));
    }
  });
})

app.set('port', (process.env.PORT || 8080));
app.listen(app.get('port'),function(){
	console.log('Server started on port '+app.get('port'));
});
