#include "Command.h"
#include "Cube.h"

void MoveRightCommand::Exec(Cube& cube)
{
	cube.MoveRight();
}

void MoveLeftCommand::Exec(Cube& cube)
{
	cube.MoveLeft();
}

void MoveUpCommand::Exec(Cube& cube)
{
	cube.MoveUp();
}

void MoveDownCommand::Exec(Cube& cube)
{
	cube.MoveDown();
}
