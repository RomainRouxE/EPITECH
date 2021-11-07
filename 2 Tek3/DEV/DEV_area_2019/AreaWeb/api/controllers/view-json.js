module.exports = {


  // friendlyName: 'View json',
  //
  //
  // description: 'Display "about.json" page.',
  //
  //
  // exits: {
  //
  //   // success: {
  //   //   redirect: 'about.json'
  //   // }
  //
  // },

    friendlyName: 'View faq',


    description: 'Display "FAQ" page',

    fn: async function (req, res) {
	console.log("About.json :");
	var fs = require("fs");
	fs.readFile('about.json', function (err, data) {
	    if (err) {
		return console.error(err);
	    }
	    console.log("Asynchronous read: " + data.toString());

	});
	// Respond with view.
	return ;
    }
};
