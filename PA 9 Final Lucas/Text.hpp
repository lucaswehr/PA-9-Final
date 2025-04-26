#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Rectangle.hpp"

class Text : public Shape
{
public:

	Text(const std::string& fontPath, const std::string& title, float x, float y, sf::Color color, int size);
		
	void draw(sf::RenderWindow& window) override;

	sf::FloatRect getBounds() override;

	sf::Text& getText();

private:

	sf::Font font;
	sf::Text text;


};
