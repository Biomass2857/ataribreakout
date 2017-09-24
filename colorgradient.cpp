#include "colorgradient.hpp"

Color getColorFromGradient(double value, double max, const ColorGradient &gradient)
{
	if(value > max)
	{
		return gradient.at(gradient.size() - 1);
	}
	else if(gradient.size() > 1)
	{
		double innerRatio = value / max;
		unsigned int index = 0;
		
		double gSize = static_cast<double>(gradient.size());
		while(innerRatio - (1 / (gSize - 1)) > 0)
		{
			innerRatio -= (1 / (gSize - 1));
			index++;
		}
		
		innerRatio *= (gSize - 1);
		
		if(index == gradient.size() - 1)
			return gradient.at(index);
		else
		{
			Color cola = gradient.at(index);
			Color colb = gradient.at(index + 1);
			
			unsigned char r = 0, g = 0, b = 0;
			
			if(cola.r > colb.r)
				r = cola.r - abs(cola.r - colb.r) * innerRatio;
			else if(cola.r < colb.r)
				r = cola.r + abs(cola.r - colb.r) * innerRatio;
			else if(cola.r == colb.r)
				r = cola.r;
			
			if(cola.g > colb.g)
				g = cola.g - abs(cola.g - colb.g) * innerRatio;
			else if(cola.g < colb.g)
				g = cola.g + abs(cola.g - colb.g) * innerRatio;
			else if(cola.g == colb.g)
				g = cola.g;
				
			if(cola.b > colb.b)
				b = cola.b - abs(cola.b - colb.b) * innerRatio;
			else if(cola.b < colb.b)
				b = cola.b + abs(cola.b - colb.b) * innerRatio;
			else if(cola.b == colb.b)
				b = cola.b;
			
			return Color(r, g, b);
		}
	}
	else if(gradient.size() == 1)
		return gradient.at(0);
	else
		return Color::White;
}

ColorGradient getDefaultGradient()
{
	vector<Color> ret;
	
	ret.push_back(Color(236, 240, 241));
	ret.push_back(Color(189, 195, 199));
	
	ret.push_back(Color(231, 76, 60));
	ret.push_back(Color(192, 57, 43));
	
	ret.push_back(Color(46, 204, 113));
	ret.push_back(Color(39, 174, 96));
	
	ret.push_back(Color(52, 152, 219));
	ret.push_back(Color(41, 128, 185));
	
	ret.push_back(Color(155, 89, 182));
	ret.push_back(Color(142, 68, 173));
	
	ret.push_back(Color(52, 73, 94));
	ret.push_back(Color(44, 62, 80));
	
	return ret;
}

Color invertColor(const Color &other)
{
	return Color(255 - other.r, 255 - other.g, 255 - other.b);
}
