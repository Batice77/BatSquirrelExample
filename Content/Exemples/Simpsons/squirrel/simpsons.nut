httpGet("https://thesimpsonsquoteapi.glitch.me/quotes?count=5",
	function(content) {
		local json = compilestring("return "+content)();
		foreach(result in json) {
			local simQuote = SimpsonsQuote(result);
			httpGet(simQuote.imageURL(),
				function(content) {
					simQuote.setImage(content);
					addQuoteToWidget(simQuote);
				},
				function() {
					print("error");
				}
			);
		}
	},
	function() {
		print("error");
	}
);