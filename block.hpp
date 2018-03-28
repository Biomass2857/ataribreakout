#ifndef BLOCK_HPP
#define BLOCK_HPP
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
#include "colorgradient.hpp"

using namespace std;
using namespace sf;

class Block
{
	public:
		Block();
		Block(Vector2u, double, double, unsigned int);
		Block(const Block&);
		~Block();
		
		Block& operator=(const Block&);
		
		void setHitCount(unsigned int);
		
		void hit();
		
		void setSize(Vector2u);
		void setPosition(double, double);
		
		Vector2u getSize();
		Vector2f getPosition();
		
		bool canBeDeleted();
		
		void render(RenderWindow*);
		
	protected:
		void resetShapeNText();
	
		RectangleShape shape;
		Text text;
		Font font;
		stringstream ss;
		Vector2u size;
		Vector2f position;
		unsigned int hitCount;
		static ColorGradient defaultGradient;
		Color bgColor;
		Color textColor;
};

#endif
