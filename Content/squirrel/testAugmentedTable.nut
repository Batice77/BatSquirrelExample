::print("xD");
//print(lol);
trop <- "bien";

function x() {
	print(trop);
	print(this);
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

function _tostring() {
	return "loqqsdqsd";
}

print(this);

return "lol";