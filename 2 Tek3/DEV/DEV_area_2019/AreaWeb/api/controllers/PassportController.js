/**
 * PassportController
 *
 * @description :: Server-side actions for handling incoming requests.
 * @help        :: See https://sailsjs.com/docs/concepts/actions
 */

var passport = require('passport');

module.exports = {
  facebookAuth: function(req, res, next) {
      passport.authenticate('facebook', { scope: ['email']})(req, res, next);
  },

  googleAuth: function(req, res) {
    passport.authenticate('google', { scope: ['email', 'profile'] })(req, res);
  },

  githubAuth: function(req, res) {
    passport.authenticate('github', { scope: ['email', 'profile'] })(req, res);
  },

  spotifyAuth: function(req, res) {
    passport.authenticate('spotify', { scope: ['email', 'profile'] })(req, res);
  },



  facebookCallback: function(req, res, next) {
     passport.authenticate('facebook', function(err, user) {
       if(err) {
        // redirect to login page
        console.log('fb callback error: '+err);
      } else {
      console.log('facebook credentials');
      console.log(user);
      // res.json(user);
      res.redirect("/welcome");
      }
    })(req, res, next);
  },

  googleCallback: function(req, res, next) {
    passport.authenticate('google', function(err, user) {
      if(err) {
        // redirect to login page
        console.log('google callback error: '+err);
      } else {
        console.log('google credentials');
        console.log(user);
        var fs = require("fs");
        var myJSON = JSON.stringify(user);
        fs.writeFile('google.txt', myJSON, function(err) {
            if (err) {
                return console.error(err);
            }
        });
        //res.json(user);
        res.redirect("/welcome");
      }
    })(req, res, next);
  },

    githubCallback: function(req, res, next) {
    passport.authenticate('github', function(err, user) {
      if(err) {
          // redirect to login page
          console.log('github callback error: '+err);
      } else {
        console.log('github credentials');
        console.log(user);
        console.log("Data written successfully!");
        //res.json(user);
        res.redirect("/welcome");
      }
    })(req, res, next);
    },

    spotifyCallback: function(req, res, next) {
    passport.authenticate('spotify', function(err, user) {
      if(err) {
          // redirect to login page                                                                                                                                                           
          console.log('spotify callback error: '+err);
      } else {
	console.log('spotify credentials');
	console.log(user);
	console.log("Data written successfully!");
        //res.json(user);                                                                                                                                                                     
        res.redirect("/welcome");
      }
    })(req, res, next);
    },


};
