'use strict';

var passport = require('passport'),
  FacebookStrategy = require('passport-facebook').Strategy,
  request = require('request');


var verifyHandler = function(req, token, tokenSecret, profile, done) {

  process.nextTick(function() {
    var url = 'https://graph.facebook.com/v2.10/me?access_token=%s&fields=id,email,first_name,last_name';
    url = url.replace('%s', token);

    var options = {method: 'GET', url: url, json: true};
    request(options, function (err, response) {
      if (err) {
        return done(null, null);
      }

      var data = {
        id: response.body.id,
        first_name: response.body.first_name,
        last_name: response.body.last_name,
        email: response.body.email
      };

      return done(null, data);
    });
  });
};

passport.use(new FacebookStrategy({
  clientID: '206963083720181',
  clientSecret: 'f8a38b4568dc7311c8178c6e0262cfa3',
  callbackURL: '/api/v1/auth/facebook/callback',
  passReqToCallback: true
}, verifyHandler));
