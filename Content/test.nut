/*local bb = 5;
bb--;
if(bb<5) return false;
return true;*/

/*a <- {
	pp = function(bool, bo4) 
	{
		print(bool);
		print(bo4);
	}
}*/

class a {
	lol = 5
	function pp(myArray) 
	{
		foreach (item in myArray) {
			print(item);
		}
	}
}

class c {
	lol = 10
}

b<-a()
b=c()
print(b.lol)

printMap <- function(map) {
	foreach(idx,val in map) {
		print(idx);
		print(val);
	}
}

i <- 0
name <- "l'ami"
return "Bonjour "+name