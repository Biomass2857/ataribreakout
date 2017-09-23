#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <strings.h>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "pad.hpp"

using namespace std;
using namespace sf;

class Game
{
	public:
		Game();
		Game(Vector2u, string);
		~Game();
		
		int start();
		
	protected:
		RenderWindow *window;
		Pad pad;
		Event event;
		Vector2u resolution;
		string title;
};	

#endif
