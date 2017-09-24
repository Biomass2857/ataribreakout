#ifndef BALL_HPP
#define BALL_HPP
#include <SFML/Graphics.hpp>
#include <cmath>
#include "block.hpp"

#define PI atan(1) * 4

using namespace std;
using namespace sf;

class Ball
{
	public:
		Ball();
		Ball(double, double, double, double, double);
		~Ball();
		
		void setPosition(double, double);
		void setRadius(double);
		void setAbsVel(double);
		void setAngle(double);
		void addUp();
		
		void invertXVelocity();
		void invertYVelocity();
		
		double getRadius();
		Vector2f getPosition();
		double getAngle();
		
		// Only 4 fun
		bool colliding(Ball&);
		
		// ÜBERARBEITEN
		bool collidingX(Block&);
		bool collidingY(Block&);
		
		void render(RenderWindow*);
	protected:
		void resetShape();
		void reCalcVelocities();
	
		CircleShape shape;
		Color col;
		double radius;
		bool copied;
		bool extraHit;
		double angle;
		double velX, velY, absVel;
		double x, y;
		bool isColliding;
};

#endif
