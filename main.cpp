#include <iostream>
#include <SFML/Graphics.hpp>
#include <strings.h>

using namespace std;
using namespace sf;

int main(int argc, char **argv)
{
	Vector2u wSize = Vector2u(600, 600);
	RenderWindow window(VideoMode(wSize.x, wSize.y), "Atari break out");
	Event event;
	
	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			if(event.type == Event::Closed)
				window.close();
		}
		
		window.clear(Color::White);
		window.display();
	}
	
	return 0;
}
