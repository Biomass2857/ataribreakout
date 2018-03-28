#include "ball.hpp"

collisionpacket::collisionpacket()
{
	is = false;
	angle = 0;
}

collisionpacket::~collisionpacket() {}

Ball::Ball()
{
	isCollidingX = false;
	isCollidingY = false;
	isCollidingCorner = false;
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
	isCollidingX = false;
	isCollidingY = false;
	isCollidingCorner = false;
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
	while(tangle < 0)
		tangle += 360;
	
	while(tangle >= 360)
		tangle -= 360;
	
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
	if(velX == 0)
	{
		if(velY > 0)
		{
			angle = 90;
		}
		else if(velY < 0)
		{
			angle = 270;
		}
		else if(velY == 0)
		{
			angle = 0; // There's no undefined in C++
		}
	}
	else
		angle = 180 * atan(velY / velX) / PI;
}

void Ball::invertYVelocity()
{
	velY = -velY;
	if(velX == 0)
	{
		if(velY > 0)
		{
			angle = 90;
		}
		else if(velY < 0)
		{
			angle = 270;
		}
		else if(velY == 0)
		{
			angle = 0; // There's no undefined in C++
		}
	}
	else
		angle = 180 * atan(velY / velX) / PI;
}

double Ball::getRadius()
{
	return radius;
}

Vector2f Ball::getPosition()
{
	return Vector2f(x, y);
}

double Ball::getAngle()
{
	return angle;
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
				if(!isCollidingX)
				{
					isCollidingX = true;
					return true;
				}
				else
					return false;
			}
			else
			{
				isCollidingX = false;
				return false;
			}
		}
		else
		{
			isCollidingX = false;
			return false;	
		}
	}
	else
	{
		isCollidingX = false;
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
				if(!isCollidingY)
				{
					isCollidingY = true;
					return true;
				}
				else
					return false;
			}
			else
			{
				isCollidingY = false;
				return false;
			}
		}
		else
		{
			isCollidingY = false;
			return false;
		}
	}
	else
	{
		isCollidingY = false;
		return false;
	}
}

struct collisionpacket Ball::cornerCollision(Block &other)
{
	struct collisionpacket ret;
	
	ret.angle = 0;
	ret.is = ((radius >= sqrt(pow(other.getPosition().x - x, 2) + pow(other.getPosition().y - y, 2)) || radius >= sqrt(pow(other.getPosition().x + other.getSize().x - x, 2) + pow(other.getPosition().y - y, 2)) || radius >= sqrt(pow(other.getPosition().x - x, 2) + pow(other.getPosition().y + other.getSize().y - y, 2)) || radius >= sqrt(pow(other.getPosition().x + other.getSize().x - x, 2) + pow(other.getPosition().y + other.getSize().y - y, 2))) && ((x < other.getPosition().x || x > other.getPosition().x + other.getSize().x) && (y < other.getPosition().y || y > other.getPosition().y + other.getSize().y)));
	
	if(ret.is)
	{
		if(!isCollidingCorner)
		{
			isCollidingCorner = true;
			if(x < other.getPosition().x && y < other.getPosition().y)
				ret.angle = 180 * atan((other.getPosition().x - x) / (other.getPosition().y - y)) / PI;
			
			if(x > other.getPosition().x + other.getSize().x && y < other.getPosition().y)
				ret.angle = 180 * atan((other.getPosition().x + other.getSize().x - x) / (other.getPosition().y - y)) / PI;
			
			if(x > other.getPosition().x && y > other.getPosition().y + other.getSize().y)
				ret.angle = 180 * atan((other.getPosition().x - x) / (other.getPosition().y + other.getSize().y - y)) / PI;
			
			if(x > other.getPosition().x + other.getSize().x && y > other.getPosition().y + other.getSize().y)
				ret.angle = 180 * atan((other.getPosition().x + other.getSize().x - x) / (other.getPosition().y + other.getSize().y - y)) / PI;
			
			if(x > other.getPosition().x && y > other.getPosition().y && x < other.getPosition().x + other.getSize().x && y < other.getPosition().y + other.getSize().y)
				ret.is = false;
			
			return ret;
		}
		else
		{
			ret.is = false;
			return ret;
		}
	}
	else
		return ret;
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
