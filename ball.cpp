#include "ball.hpp"

Ball::Ball()
{
	isColliding = false;
	x = 0;
	y = 0;
	radius = 5;
	col = Color::Black;
	angle = 0;
	absVel = 0;
	resetShape();
	reCalcVelocities();
}

Ball::Ball(double tradius, double tx, double ty, double tabsvel, double tangle)
{
	isColliding = false;
	radius = tradius;
	x = tx;
	y = ty;
	absVel = tabsvel;
	angle = tangle;
	col = Color::Black;
	resetShape();
	reCalcVelocities();
}

Ball::~Ball() {}

void Ball::setPosition(double tx, double ty)
{
	x = tx;
	y = ty;
	resetShape();
}

void Ball::setRadius(double r)
{
	radius = r;
	resetShape();
}

void Ball::setAbsVel(double vel)
{
	absVel = vel;	
	reCalcVelocities();
}

void Ball::setAngle(double tangle)
{
	angle = tangle;
	reCalcVelocities();
}

void Ball::addUp()
{
	x += velX;
	y += velY;
	resetShape();
}

void Ball::invertXVelocity()
{
	velX = -velX;
	angle = 360 * tan(velY / velX) / (2 * PI);
}

void Ball::invertYVelocity()
{
	velY = -velY;
	angle = 360 * tan(velY / velX) / (2 * PI);
}

double Ball::getRadius()
{
	return radius;
}

Vector2f Ball::getPosition()
{
	return Vector2f(x, y);
}

bool Ball::colliding(Ball &other)
{
	if(radius + other.getRadius() >= sqrt(pow(x - other.getPosition().x, 2) + pow(y - other.getPosition().y, 2)))
		return true;
	else
		return false;
}

// ÜBERARBEITEN

bool Ball::collidingX(Block &other)
{
	if(other.getPosition().y - radius <= y && y <= other.getPosition().y + other.getSize().y + radius)
	{
		if(other.getPosition().x - radius <= x && x <= other.getPosition().x + other.getSize().x + radius)
		{
			if(y + radius < other.getPosition().y + other.getSize().y && y - radius > other.getPosition().y)
			{
				if(!isColliding)
				{
					isColliding = true;
					return true;
				}
				else
					return false;
			}
			else
			{
				isColliding = false;
				return false;
			}
		}
		else
		{
			isColliding = false;
			return false;	
		}
	}
	else
	{
		isColliding = false;
		return false;
	}
}

bool Ball::collidingY(Block &other)
{
	if(other.getPosition().x - radius <= x && x <= other.getPosition().x + other.getSize().x + radius)
	{
		if(other.getPosition().y - radius <= y && y <= other.getPosition().y + other.getSize().y + radius)
		{
			if(x + radius < other.getPosition().x + other.getSize().x && x - radius > other.getPosition().x)
			{
				if(!isColliding)
				{
					isColliding = true;
					return true;
				}
				else
					return false;
			}
			else
			{
				isColliding = false;
				return false;
			}
		}
		else
		{
			isColliding = false;
			return false;
		}
	}
	else
	{
		isColliding = false;
		return false;
	}
}

// ÜBERARBEITEN

void Ball::render(RenderWindow *window)
{
	window->draw(shape);
}

void Ball::resetShape()
{
	shape.setOrigin(radius * 0.5, radius * 0.5);
	shape.setPosition(x, y);
	shape.setRadius(radius);
	shape.setFillColor(col);
}

void Ball::reCalcVelocities()
{
	velX = sin(angle * (2 * PI) / 360) * absVel;
	velY = cos(angle * (2 * PI) / 360) * absVel;
}
