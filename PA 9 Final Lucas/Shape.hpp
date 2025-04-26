#pragma once
#include "Rectangle.hpp"

//enables polymorphism and inheritence on the getBounds and draw function
class Shape
{
public:

	virtual void draw(sf::RenderWindow& window) = 0;

	virtual sf::FloatRect getBounds() = 0;

	virtual ~Shape() = default;

};
