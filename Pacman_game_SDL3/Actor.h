#pragma once
class Actor
{
private:
	int x;
	int y;
	int speed;
public:
	Actor(int, int, int);
	virtual void drawActor();
	~Actor();

private:
};

