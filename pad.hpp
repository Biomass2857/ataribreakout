#ifndef PAD_HPP
#define PAD_HPP
#include <vector>
#include <iostream>
#include "ball.hpp"
#include "block.hpp"

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
		
		void addBlocksRandomly(unsigned int);
		
		void spawnTest();
		// Debug
		
		void shiftRow();
	protected:
		vector<Ball> balls;
		vector<Block> blocks;
		Vector2u size;
};

#endif
