#ifndef PAD_HPP
#define PAD_HPP
#include <vector>
#include "ball.hpp"

class Pad
{
	public:
		Pad();
		~Pad();
		
		void display(RenderWindow*);
		
		void update();
		
		// Debug
		void addBallsRandomly(unsigned int);
	protected:
		vector<Ball> balls;
};

#endif
