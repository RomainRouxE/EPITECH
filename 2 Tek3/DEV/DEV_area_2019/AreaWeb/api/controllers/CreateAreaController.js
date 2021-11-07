/**
 * CreateAreaController
 *
 * @description :: Server-side actions for handling incoming requests.
 * @help        :: See https://sailsjs.com/docs/concepts/actions
 */
var actionApp;
var trigger;
var request = require('request');
var fs = require("fs");

module.exports = {

    create:function(req, res)
    {
        actionApp = req.param('action-app');

        console.log("actionApp detected: " + actionApp);

        if (actionApp == "twitter") {
            // conection to twitter
                // now using just my account
                // get token etc and stock it

            // go to trigger page
            var triggers = [{"name":'search hashtag'}, {"name":'none'}, {"name":'none'}];
            res.view('CreateAreaSelectTrigger', {triggers:triggers});
      }
        else {
            console.log("Not implemented yet: " + actionApp);
            res.redirect('/');
        }
    },

    trig: function (req, res)
    {
        //
        trigger = req.param('action-trigger');
        console.log("var trigger = " + trigger);
        //
        if (trigger == "search hashtag")
        {
            console.log("trigger is :" + trigger);
            var opts = [{"name": 'search hashtag'}];
            res.view('list', {opts:opts});
        }
        else {
            console.log("trigger not implemented yet: " + trigger);
            res.redirect('/');
        }
    },

    reaction:function(req, res)
    {
        reactionApp = req.param('reaction-app');

        console.log("reactionApp detected: " + actionApp);

        if (reactionApp == "twitter") {
            // go to trigger page
            var triggers = [{"name":'favorite'}, {"name":'retweet'}, {"name":'none'}];
            res.view('CreateReactionSelectTrigger', {triggers:triggers});
        }
        else {
            console.log("Not implemented yet: " + actionApp);
            res.redirect('/');
        }
    },

    reactionTrig: function(req, res)
    {
        console.log("got trigger for reaction and need to implement it !");
        trigger = req.param('trigger-info');

        if (trigger == "favorite") {
            console.log("redirect to favorite");
            res.redirect('/twitter/favIt');
        }
        else if (trigger == "retweet") {
            console.log("redirect to retweet");
            res.redirect('/twitter/retweetIt');
        }
        else {
            console.log("Not implemented yet.");
            res.redirect('/');
        }
    },
};
