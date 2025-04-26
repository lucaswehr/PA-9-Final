#include "Circle.hpp"
#include "Animation.hpp"


//passes in the cannonball texture and makes it so that it follows the circle. Construtor also creates a circle
Circle::Circle(float x, float y, float radius, sf::Color color, float xSpeed, float ySpeed, sf::Texture& texture) :
	animation(texture, 10, 1, 0.06f, 0, false),  // Animation is initialized here
	xSpeed(xSpeed), ySpeed(ySpeed), xCord(x), yCord(y)
{
	this->circle.setPosition(sf::Vector2f(x, y));
	this->circle.setRadius(radius);
	this->circle.setFillColor(color);
	this->circle.move(sf::Vector2f(xSpeed, ySpeed));

	
	circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));
	sf::FloatRect spriteBounds = animation.getSprite().getLocalBounds();
	animation.getSprite().setOrigin(sf::Vector2f(spriteBounds.size.x / 2.f, spriteBounds.size.y / 2.f));
	animation.getSprite().setPosition(sf::Vector2f(x,y));
}

void Circle::draw(sf::RenderWindow& window)
{
	window.draw(animation.getSprite());

}

void Circle::Update(float deltaTime)
{
	this->circle.move(sf::Vector2f(xSpeed, ySpeed));
	animation.setPosition(circle.getPosition().x, circle.getPosition().y);
	animation.update(deltaTime);
}


sf::FloatRect Circle::getBounds()
{
	return circle.getGlobalBounds();

}

float Circle::getRadius()
{
	return circle.getRadius();
}

void Circle::setSpeed(float xSpeed, float ySpeed)
{
	this->xSpeed = xSpeed;

	this->ySpeed = ySpeed;

}

void Circle::setRandomCords()
{
	float randomNum = std::rand() % 571;

	circle.setPosition({circle.getPosition().x, randomNum});

}

//Changes the size of the circle randomly
void Circle::setRandomSize()
{
	float randomNum = std::rand() % 60 + 10;

	sf::Vector2f currentPos = circle.getPosition();

	circle.setRadius(randomNum);
	circle.setOrigin(sf::Vector2f(randomNum, randomNum));
	circle.setPosition(currentPos);

}

bool Circle::checkCircles(const sf::Vector2f& pos1, float r1, const sf::Vector2f& pos2, float r2)
{
	sf::Vector2f diff = pos1 - pos2;
	float distance = std::sqrt(diff.x * diff.x + diff.y * diff.y);
	return distance < (r1 + r2);
}

sf::CircleShape Circle::getShape()
{
	return this->circle;
}

//Acurretly changes the sprite size with the circle size
void Circle::shapeToSprite()
{

	float radius = circle.getRadius();


	sf::FloatRect spriteBounds = animation.getSprite().getLocalBounds();

	float spriteWidth = spriteBounds.size.x;
	float spriteHeight = spriteBounds.size.y;

	float scaleFactor = (radius * 2.f) / spriteWidth;

	if (flipped)
	{
		animation.setScale(sf::Vector2f(scaleFactor, scaleFactor));
	}
	else {
		animation.setScale(sf::Vector2f(-scaleFactor, scaleFactor));
	}

	flipped = !flipped;

}

