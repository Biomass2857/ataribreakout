#include <iostream>
#include <SFML/Graphics.hpp>
#include <strings.h>
#include "game.hpp"

using namespace std;
using namespace sf;

int main(int argc, char **argv)
{
	Game atari(Vector2u(700, 800), "Atari breakout");
	
	Ball x(4, 8, 7, 0, 0);
	
	Block y(Vector2u(5, 5), 0, 0, 100);
	
	struct collisionpacket collision;
	
	collision = x.cornerCollision(y);
	
	cout << (collision.is ? "true" : "false") << endl;
	cout <<"Angle: "<< collision.angle * 45 / atan(1) << endl;
	
	return atari.start();
	return 0;
}
