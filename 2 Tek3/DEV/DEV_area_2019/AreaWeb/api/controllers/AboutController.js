/**
 * AboutController
 *
 * @description :: Server-side actions for handling incoming requests.
 * @help        :: See https://sailsjs.com/docs/concepts/actions
 */

module.exports = {

  retrn:function(req, res){
      var fs = require('fs');

      fs.readFile('about.json', 'utf8', function(err, contents) {
          var data = JSON.parse(contents);
          console.log(contents);
          res.json(data);
      });
  }

};
