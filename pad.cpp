#include "pad.hpp"

Pad::Pad() {}

Pad::~Pad() {}

void Pad::display(RenderWindow *window)
{
	for(size_t i = 0; i < balls.size(); i++)
	{
		balls.at(i).render(window);
	}
}
		
void Pad::update()
{
	for(size_t i = 0; i < balls.size(); i++)
	{
		balls.at(i).addUp();
	}
}

void Pad::addBallsRandomly(unsigned int count)
{
	for(size_t i = 0; i < count; i++)
	{
		balls.push_back(Ball(20, 0, 0, double(rand() % 4) + 1, double(rand() % 45) + 22.5));
	}
}
