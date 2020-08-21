::print("Hello Augmented Table");

function x() {
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
	return "TheAugmentedTable";
}

print(this);
return this;