'use strict';

var passport = require('passport'),
  GoogleStrategy = require('passport-github2').Strategy;

//var verifyHandler = function(req, token, tokenSecret, profile, done) {                                                                                                                      
var verifyHandler = function (accessToken, refreshToken, profile, cb, done) {

  var data = {
    id: cb.id,
    name: cb.displayName,
    email: cb.emails[0].value,
    emailVerified: cb.emails[0].verified
  };

  return done(null, data);
};

passport.use(new GoogleStrategy({
  clientID: 'aa33d0cb71918aea455d',
  clientSecret: '8d66409d54fb3adcff454a9a5794299091e8d5fd',
  callbackURL: '/api/v1/auth/github/callback',
  passReqToCallback: true
}, verifyHandler));
