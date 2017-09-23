#include "ball.hpp"

Ball::Ball()
{
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

double Ball::getRadius()
{
	return radius;
}

Vector2f Ball::getPosition()
{
	return Vector2f(x, y);
}

void Ball::render(RenderWindow *window)
{
	window->draw(shape);
}

void Ball::resetShape()
{
	shape.setPosition(x, y);
	shape.setRadius(radius);
	shape.setOrigin(radius * 0.5, radius * 0.5);
	shape.setFillColor(col);
}

void Ball::reCalcVelocities()
{
	velX = sin(angle * (2 * PI) / 360) * absVel;
	velY = cos(angle * (2 * PI) / 360) * absVel;
}
