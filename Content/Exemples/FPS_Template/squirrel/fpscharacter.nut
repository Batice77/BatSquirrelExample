function onMoveForward(value)
{
	if(character) {
		character.addMovementInput(character.getActorForward(), value);
	}
}

function onMoveRight(value)
{
	if(character) {
		character.addMovementInput(character.getActorRight(), value);
	}
}

function onTurn(value)
{
	if(character) {
		character.addYaw(value);
	}
}

function onLookUp(value)
{
	if(character) {
		character.addPitch(value);
	}
}

function onJump()
{
	if(character) {
		character.jump();
	}
}

FPSCharacter.x <- 1;
Projectile.vel <- 3000;

function onFire()
{
	if(character) {
		character.playFireAnimAndSound();
		
		local x = character.x;
		local pair = x%2==0 ? true : false;
		local offsetY = pair?25:0;
		for(local i=-x/2; i<=x/2-pair.tointeger(); i++) {
			character.setGunOffset(Vector(100, i*50+offsetY, -10));
			local proj = Projectile(character.getWorldShootLocation(), character.getWorldCameraRotation());
			proj.launch(proj.vel);
		}
	}
}

/*local oldOnHit = Projectile.onHit;
function Projectile::onHit(lol)
{
	oldOnHit(lol);
	
	//this.launch(-3000.0);
	
	vel = vel/1.15;
	launch(vel);
	
	if(character.x <= 10)
		character.x++;
	if(character.x>10) character.x = 10;
}*/