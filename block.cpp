#include "block.hpp"

ColorGradient Block::defaultGradient = getDefaultGradient();

Block::Block()
{
	hitCount = 1;
	size = Vector2u(100, 100);
	position = Vector2f(0, 0);
	font.loadFromFile("mono.ttf");
	text.setFont(font);
	resetShapeNText();
}

Block::Block(Vector2u tsize, double x, double y, unsigned int thitcount)
{
	hitCount = thitcount;
	size = tsize;
	font.loadFromFile("mono.ttf");
	text.setFont(font);
	position.x = x;
	position.y = y;
	resetShapeNText();
}

Block::Block(const Block &other)
{
	*this = other;
}

Block::~Block() {}

Block& Block::operator=(const Block &other)
{
	hitCount = other.hitCount;
	position = other.position;
	size = other.size;
	
	font.loadFromFile("mono.ttf");
	text.setFont(font);
	
	resetShapeNText();
	
	return *this;
}

void Block::setHitCount(unsigned int thitcount)
{
	hitCount = thitcount;
	resetShapeNText();
}
		
void Block::hit()
{
	if(hitCount > 0)
		hitCount--;
	
	resetShapeNText();
}

void Block::setSize(Vector2u tsize)
{
	size = tsize;
	resetShapeNText();
}

void Block::setPosition(double tx, double ty)
{
	position.x = tx;
	position.y = ty;
	resetShapeNText();
}

Vector2u Block::getSize()
{
	return size;
}

Vector2f Block::getPosition()
{
	return position;
}

bool Block::canBeDeleted()
{
	return hitCount == 0;
}

void Block::render(RenderWindow *window)
{
	window->draw(shape);
	window->draw(text);
}

void Block::resetShapeNText()
{
	bgColor = getColorFromGradient(hitCount, pow(2, 7), defaultGradient);
	shape.setFillColor(bgColor);
	shape.setSize(Vector2f(size.x, size.y));
	shape.setPosition(position.x, position.y);
	
	textColor = invertColor(bgColor);
	text.setCharacterSize(20);
	text.setFillColor(Color::Black);	
	
	ss << hitCount;
	text.setString(ss.str());
	ss.str("");
	
	text.setPosition(position.x + (size.x - text.getGlobalBounds().width) * 0.5, position.y + (size.y - text.getGlobalBounds().height) * 0.5);
}
