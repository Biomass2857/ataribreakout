#include <iostream>
#include <SFML/Graphics.hpp>
#include <strings.h>
#include "game.hpp"

using namespace std;
using namespace sf;

int main(int argc, char **argv)
{
	Game atari(Vector2u(700, 800), "Atari breakout");
	
	return atari.start();
}
