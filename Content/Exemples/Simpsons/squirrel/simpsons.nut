httpGet("https://thesimpsonsquoteapi.glitch.me/quotes?count=5",
	function(content) {
		print(content);
	},
	function() {
		print("error")
	}
);

