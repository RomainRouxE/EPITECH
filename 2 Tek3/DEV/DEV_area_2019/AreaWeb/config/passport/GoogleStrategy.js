'use strict';

var passport = require('passport'),
  GoogleStrategy = require('passport-google-oauth20').Strategy;

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
  clientID: '621182094936-vq5ua43qnia2asr7ipkb6jihhthcja38.apps.googleusercontent.com',
  clientSecret: 'nXHZ5lLCPELeyKwJaEpkPsAj',
  callbackURL: '/api/v1/auth/google/callback',
  passReqToCallback: true
}, verifyHandler));
