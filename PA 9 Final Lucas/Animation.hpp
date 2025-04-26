#pragma once
#include "Rectangle.hpp"
//#include "Circle.hpp"

enum class Direction {
    None,
    Left,
    Right
};


class Animation 
{
public:

    

    Animation(sf::Texture& texture, int frameCount, int frameRows, float frameDuration, int rowToAnimate = 0, bool enableFlip = false)
        : texture(texture), frameCount(frameCount), frameDuration(frameDuration), currentFrame(0), elapsedTime(0.f), sprite(texture), frameRows(frameRows), rowToAnimate(rowToAnimate), enableFlip(enableFlip) {

        updateTexture();
    }

    //Updates each frame extremely fast making it look like its animating 
    void update(float deltaTime) {
        elapsedTime += deltaTime;

        if (elapsedTime >= frameDuration) {
            elapsedTime = 0.f;
            currentFrame = (currentFrame + 1) % frameCount;  
            updateTexture();  
        }
    }

    void setPosition(float x, float y) {
        sprite.setPosition(sf::Vector2f(x, y));
    }

    void setScale(float scaleX, float scaleY) {
        sprite.setScale(sf::Vector2f(scaleX, scaleY));
    }

    void draw(sf::RenderWindow& window)  {
        window.draw(sprite);
    }

    sf::Sprite& getSprite() {
        return sprite;
    }

    void setDirection(Direction dir) {
        direction = dir;
        updateTexture(); // Update flip immediately
    }

    void setScale(const sf::Vector2f& scale) {
        this->sprite.setScale(scale);
    }


private:

    sf::Sprite sprite;
    sf::Texture& texture;
    int frameCount;
    int frameRows;
    int rowToAnimate;
    float frameDuration;
    int currentFrame;
    float elapsedTime;
    Direction direction;
    bool enableFlip;

    void updateTexture()
    {
        int frameWidth = texture.getSize().x / frameCount;  // Divide by frame count (number of columns)
        int frameHeight = texture.getSize().y / frameRows; //4 rows in the sprite sheet

        // Calculates the texture coordinates for the 4th row)
        int left = frameWidth * currentFrame;   // The x-coordinate of the current frame
        int top = frameHeight * rowToAnimate;  // The y-coordinate for the 4th row 

        // Set the texture rect for the pug sprite 
        sprite.setTextureRect(sf::IntRect({ left, top }, { frameWidth, frameHeight }));

        //Flips the pug on the x-axis when moving left
        if (enableFlip)
        {
            sprite.setScale(sf::Vector2f(1.5f * (direction == Direction::Left ? -1.f : 1.f), 1.5f));
            sprite.setOrigin(sf::Vector2f(frameWidth / 3.f, frameHeight / 3.f));                     
        }         
    }  
};