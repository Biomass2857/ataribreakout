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

void Game::delay(unsigned int ms)
{
	delayClock.restart();
	while(delayClock.getElapsedTime().asMilliseconds() < ms);
}

int Game::start()
{
	srand(time(NULL));
	window = new RenderWindow(VideoMode(resolution.x, resolution.y), title);
	
	bool spaceBlocking = false;
	unsigned prog = 0;
	
	pad.setSize(resolution);
	
	while(window->isOpen())
	{
		while(window->pollEvent(event))
		{
			if(event.type == Event::Closed)
				window->close();
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Space))
		{
			if(!spaceBlocking)
			{
				spaceBlocking = true;
				pad.addBlocksRandomly(1);
				pad.addBallsRandomly(3);
			}
		}
		else
			spaceBlocking = false;
			
		delay(20);
		
		pad.update();
		
		window->clear(Color::White);
		pad.display(window);
		window->display();
	}
	
	return 0;
}
