#ifndef PAD_HPP
#define PAD_HPP
#include <vector>
#include "ball.hpp"

class Pad
{
	public:
		Pad();
		~Pad();
		
		void setSize(Vector2u);
		void display(RenderWindow*);
		
		void update();
		
		// Debug
		void addBallsRandomly(unsigned int);
	protected:
		vector<Ball> balls;
		Vector2u size;
};

#endif
