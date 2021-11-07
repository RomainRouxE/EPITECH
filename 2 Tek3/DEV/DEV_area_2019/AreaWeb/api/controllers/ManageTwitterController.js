/**
 * ManageTwitterController
 *
 * @description :: Server-side actions for handling incoming requests.
 * @help        :: See https://sailsjs.com/docs/concepts/actions
 */

var Twitter = require('twitter');
var config = require('./twitter.js');
var fs = require('fs');
var T = new Twitter(config);

module.exports = {

    searchHashtag:function(req, res){
        console.log("searching hashtag");
        var hashtag = req.param('trigger-info');
        console.log("hashtag to search is: " + hashtag);
        // Set up your search parameters
        var params = {
            q: hashtag,
            count: 10,
            result_type: 'recent',
            lang: 'en'
        };
        // Initiate your search using the above paramaters
        T.get('search/tweets', params, function(err, data, response) {
          // If there is no error, proceed
          if(!err){
              var myJSON = JSON.stringify(data);
              fs.writeFile('hashtag.txt', myJSON, function(err) {
                  if (err) {
                      console.log("error: " + err);
                  }
              });
          }
        });
        res.view('createReaction');
    },

    favorite:function(req, res){
        console.log("favoriting");
        fs.readFile('hashtag.txt', function (err, file) {
            if (err) {
                return console.error(err);
            }
            var data = JSON.parse(file.toString());
            // Loop through the returned tweets
            for(let i = 0; i < data.statuses.length; i++){
                // Get the tweet Id from the returned data
                let id = { id: data.statuses[i].id_str }
                // Try to Favorite the selected Tweet
                T.post('favorites/create', id, function(err, response){
                    // If the favorite fails, log the error message
                    if(err) {
                        console.log(err[0].message);
                    }
                    // If the favorite is successful, log the url of the tweet
                    else{
                        let username = response.user.screen_name;
                        let tweetId = response.id_str;
                        console.log('Favorited: ', `https://twitter.com/${username}/status/${tweetId}`)
                    }
                });
            }
        });
        res.redirect('/');
    },

    retweet: function(req, res){
        console.log("retweeting");
        fs.readFile('hashtag.txt', function (err, file) {
            if (err) {
                return console.error(err);
            }
            var data = JSON.parse(file.toString());
            // Loop through the returned tweets
            for(let i = 0; i < data.statuses.length; i++){
                // Get the tweet Id from the returned data
                let id = { id: data.statuses[i].id_str }
                // Try to Favorite the selected Tweet
                T.post('statuses/retweet/', id, function(err, tweet, response){
                    // If the favorite fails, log the error message
                    if(err) {
                        console.log(err);
                    } else {
                        console.log('retweet: ' + tweet);
                    }
                });
            }
        });
        res.redirect('/');
    },
};
