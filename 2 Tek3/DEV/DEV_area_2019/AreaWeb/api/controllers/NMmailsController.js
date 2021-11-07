/**
 * NMmailsController
 *
 * @description :: Server-side actions for handling incoming requests.
 * @help        :: See https://sailsjs.com/docs/concepts/actions
 */
module.exports = {


nbMails: function(req, res)
    {

        var hms = req.param('appt-time2');   // your input string
        // var target = new Date("1970-01-01 " + hms);
        var a = hms.split(':'); // split it at the colons
        // console.log("a[0] ==" + a[0]);
        // // minutes are worth 60 seconds. Hours are worth 60 minutes.
        // var seconds = (+a[0]) * 60 * 60 + (+a[1]) * 60;
        //
        // console.log(seconds);
        // console.log(target.getTime());

        var now = new Date();
        var millisTill10 = new Date(now.getFullYear(), now.getMonth(), now.getDate(), a[0], a[1], 0, 0) - now;
        if (millisTill10 < 0) {
            millisTill10 += 86400000; // it's after 10am, try 10am tomorrow.
        }
        setTimeout(function(){console.log("It's " +a[0] + ":" + a[1] + " am!")
            var fs = require("fs");
            fs.readFile('google.txt', function (err, data) {
          if (err) {
             return console.error(err);
          }
          console.log("Asynchronous read: " + data.toString());
          var txt = JSON.parse(data.toString());
          console.log(txt.id);
          console.log(txt.name);
          console.log(txt.email);
          var nodemailer = require('nodemailer');
          var transporter = nodemailer.createTransport({
         service: 'gmail',
         auth: {
                user: 'rootArea123@gmail.com',
                pass: 'Darck772103'
            }
        });
        const mailOptions = {
          from: 'rootArea123@gmail.com', // sender address
          to: txt.email, // list of receivers
          subject: 'Rappel RDV', // Subject line
          html: 'Bonjour, Il est heure de votre RDV</p>'// plain text body
        };

        transporter.sendMail(mailOptions, function (err, info) {
           if(err)
             console.log(err)
           else
             console.log(info);
        });

       });
            },  millisTill10);


        var time2 = new Date();
        console.log(time2.getTime());
        console.log("yeah bitch!");
        res.redirect("/welcome/hello");
    },

};
