#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio.hpp>

#include "Shape.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>  
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>

class Rectangle : public Shape
{
public:

	

	Rectangle(float x, float y, float width, float height, sf::Color color);

	void draw(sf::RenderWindow& window) override;

	sf::FloatRect getBounds() override;

	bool checkCeilingCollision(const sf::FloatRect& circleBounds, float velocityY);

	bool checkLandingCollision(const sf::FloatRect& circleBounds, float velocityY);

	void setRectTexture(const sf::Texture& filename);

	

private:

    sf::RectangleShape rect;

};