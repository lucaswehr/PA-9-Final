#include "Test.hpp"

void Test::testTextures()
{

	sf::Texture texture;

	if (!texture.loadFromFile("forest.jpg"))
	{
		std::cout << "Error, cannot load the texture" << std::endl;

	}
	else
	{
		std::cout << "Sucessfully loaded in the forest texture!" << std::endl;
	}

}

void Test::testFont()
{
	sf::Font font;

	std::string fontText = "Jersey10-Regular.ttf";

	if (!font.openFromFile(fontText))
	{
		std::cout << "Error, cannot load the font" << std::endl;

	}
	else
	{
		std::cout << "Sucessfully loaded in the font!" << std::endl;
	}


}

void Test::testMusic()
{
	sf::Music music;

	if (!music.openFromFile("rhythm_factorymix4.ogg"))
	{
		std::cout << "Error, cannot open music file" << std::endl;

	}
	else
	{
		std::cout << "Succesfully opened the music file!" << std::endl;
	}

}

void Test::testSound()
{
	sf::SoundBuffer sound;
	
	if (!sound.loadFromFile("Dog Bark.wav"))
	{
		std::cout << "Error, cannot load the sound" << std::endl;

	}
	else
	{
		std::cout << "Sucessfully loaded in the sound!" << std::endl;
	}


}

void Test::testWindow()
{

	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML works!");

	if (window.isOpen())
	{
		std::cout << "Window is sucessfully opened!" << std::endl;
	}
	else
	{
		std::cout << "Error, could not open window" << std::endl;
	}

	if (window.getSize().x == 800 && window.getSize().y == 600)
	{
		std::cout << "Window dimensions is 800 and 600!" << std::endl;
	}
	else
	{
		std::cout << "Window dimensions are incorrect" << std::endl;
	}
}
