::print("xD");

trop <- "bien";

function x() {
	print(trop);
	foreach(key, val in x.getinfos())
	{
		print(key+" "+val);
		if(key == "defparams") {
			foreach(val2 in val)
			{
				print(val2);
			}
		}
		else if(key == "parameters") {
			foreach(val2 in val)
			{
				print(val2);
			}
		}
	}
}

return "lol";