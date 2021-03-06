'use strict';

var passport = require('passport'),
  SpotifyStrategy = require('passport-spotify').Strategy;

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

passport.use(new SpotifyStrategy({
  clientID: '94dcefc6207c4ed78579c779bea83f09',
  clientSecret: '2e94d7680352448fa87426f90ae9058b',
  callbackURL: '/spotify/callback',
  passReqToCallback: true
}, verifyHandler));
