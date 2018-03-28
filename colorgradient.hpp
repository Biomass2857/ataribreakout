#ifndef COLORGRADIENT_HPP
#define COLORGRADIENT_HPP
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

typedef vector<Color> ColorGradient;

Color getColorFromGradient(double, double, const ColorGradient&);

// Thanks to http://flatuicolors.com
ColorGradient getDefaultGradient();

Color invertColor(const Color&);

#endif
