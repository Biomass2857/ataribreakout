#ifndef BALL_HPP
#define BALL_HPP
#include <SFML/Graphics.hpp>
#include <cmath>
#include "block.hpp"

const double PI = atan(1) * 4;

using namespace std;
using namespace sf;

struct collisionpacket
{
	collisionpacket();
	~collisionpacket();
	bool is;
	double angle;
};

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
		
		struct collisionpacket cornerCollision(Block&);
				
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
		bool isCollidingX;
		bool isCollidingY;
		bool isCollidingCorner;
};

#endif
