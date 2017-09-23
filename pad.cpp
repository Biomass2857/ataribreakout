#include "pad.hpp"

Pad::Pad() {}

Pad::~Pad() {}

void Pad::setSize(Vector2u tsize)
{
	size = tsize;
}

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
		
		if(balls.at(i).getRadius() + balls.at(i).getPosition().x < 0 || balls.at(i).getRadius() + balls.at(i).getPosition().x >= size.x)
			balls.at(i).invertXVelocity();
			
		if(balls.at(i).getRadius() + balls.at(i).getPosition().y < 0 || balls.at(i).getRadius() + balls.at(i).getPosition().y >= size.y)
			balls.at(i).invertYVelocity();
			
		for(size_t p = 0; p < balls.size(); p++)
		{
			if(p != i)
			{
				if(balls.at(i).colliding(balls.at(p)))
				{
					balls.at(i).invertXVelocity();
					balls.at(i).invertYVelocity();
					balls.at(p).invertXVelocity();
					balls.at(p).invertYVelocity();
				}
			}
		}
	}
}

void Pad::addBallsRandomly(unsigned int count)
{
	for(size_t i = 0; i < count; i++)
	{
		balls.push_back(Ball(7, rand() % size.x, rand() % size.y, double(rand() % 10) + 1, double(rand() % 45) + 22.5));
	}
}
