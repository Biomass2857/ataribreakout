#include "game.hpp"

using namespace std;
using namespace sf;

Game::Game()
{
	title = "Unknown Game";
	resolution = Vector2u(600, 600);
	window = nullptr;
}

Game::Game(Vector2u res, string ttitle)
{
	window = nullptr;
	resolution = res;
	title = ttitle;
}

Game::~Game()
{

}

int Game::start()
{
	window = new RenderWindow(VideoMode(resolution.x, resolution.y), title);
	
	while(window->isOpen())
	{
		while(window->pollEvent(event))
		{
			if(event.type == Event::Closed)
				window->close();
		}
		
		window->clear(Color::White);
		window->display();
	}
	
	return 0;
}
