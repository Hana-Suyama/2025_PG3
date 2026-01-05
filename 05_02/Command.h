#pragma once

class Cube;

class ICommand
{
public:
	virtual ~ICommand() = default;
	virtual void Exec(Cube& cube) = 0;
};

class MoveRightCommand : public ICommand {
public:
	void Exec(Cube& cube) override;
};

class MoveLeftCommand : public ICommand {
public:
	void Exec(Cube& cube) override;
};

class MoveUpCommand : public ICommand {
public:
	void Exec(Cube& cube) override;
};

class MoveDownCommand : public ICommand {
public:
	void Exec(Cube& cube) override;
};

