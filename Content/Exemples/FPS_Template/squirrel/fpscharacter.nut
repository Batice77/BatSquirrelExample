function onMoveForward(value)
{
	if(character) {
		local worldDir = Vector(1,0,0);
		character.addMovementInput(worldDir, value)
	}
}
return 8;