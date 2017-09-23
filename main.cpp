#include <iostream>
#include <SFML/Graphics.hpp>
#include <strings.h>
#include "game.hpp"

using namespace std;
using namespace sf;

int main(int argc, char **argv)
{
	Game atari(Vector2u(500, 700), "Atari breakout");
	
	return atari.start();
}
