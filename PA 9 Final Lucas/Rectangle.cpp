#include "Rectangle.hpp"

Rectangle::Rectangle(float x, float y, float width, float height, sf::Color color)
{

	this->rect.setPosition(sf::Vector2f(x, y));
	this->rect.setSize(sf::Vector2f(width, height));
	this->rect.setFillColor(color);
	

	
}

void Rectangle::draw(sf::RenderWindow& window)
{
	window.draw(this->rect);
}

sf::FloatRect Rectangle::getBounds()
{
	return rect.getGlobalBounds();
}

//Detects if the pug bonks his head on a rectangle
bool Rectangle::checkCeilingCollision(const sf::FloatRect& circleBounds, float velocityY)
{

	float circleTop = circleBounds.position.y;
	float rectBottom = rect.getGlobalBounds().position.y + rect.getGlobalBounds().size.y;
	return velocityY < 0 &&
		circleTop - velocityY <= rectBottom &&
		circleBounds.position.y > rect.getGlobalBounds().position.y &&
		circleBounds.findIntersection(rect.getGlobalBounds());
}

//Determines if the pug is on solid ground
bool Rectangle::checkLandingCollision(const sf::FloatRect& circleBounds, float velocityY)
{

	float circleBottom = circleBounds.position.y + circleBounds.size.y;
	float rectTop = rect.getGlobalBounds().position.y;

	return velocityY >= 0 &&
		circleBottom - velocityY <= rectTop + 2.f &&
		circleBounds.findIntersection(rect.getGlobalBounds());

}
void Rectangle::setRectTexture(const sf::Texture& filename)
{
	this->rect.setTexture(&filename);


}
