#pragma once
#include "Rectangle.hpp"
#include "Animation.hpp"
#include "Shape.hpp"

class Circle : public Shape
{
public:

	Circle(float x, float y, float radius, sf::Color color, float xSpeed, float ySpeed, sf::Texture& texture);
		
	void draw(sf::RenderWindow& window) override;
	
	void Update(float deltaTime);

	sf::FloatRect getBounds() override;

	float getRadius();

	void setSpeed(float xSpeed, float ySpeed);

	void setRandomCords();

	void setRandomSize();

	bool checkCircles(const sf::Vector2f& pos1, float r1, const sf::Vector2f& pos2, float r2);

	sf::CircleShape getShape();

	void shapeToSprite();

	

private:

	
	sf::CircleShape circle;

	Animation animation;

	float xSpeed;
	float ySpeed;

	float xCord;
	float yCord;

	float size;

	bool flipped = true;


};

