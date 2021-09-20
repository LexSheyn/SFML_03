#include "stdafx.h"
#include "Menu.h"

//Private functions
void Menu::initVariables()
{
	this->menuOpened = false;
}

void Menu::initBackground()
{
	this->menuBackground.setSize(sf::Vector2f(100.f, 100.f));
	this->menuBackground.setFillColor(sf::Color(0, 0, 100, 150));
	this->menuBackground.setPosition(0.f, 0.f);
}

void Menu::initTexture(std::string texture_name, std::string file_path)
{
	if (!this->textures[texture_name].loadFromFile(file_path))
	{
		std::cout << "ERROR::Menu::initTexture::Failed to load " << file_path;
		std::cout << "\n";
	}
}

void Menu::initSprite(std::string sprite_name, std::string texture_name)
{
	this->sprites[sprite_name].setTexture(this->textures[texture_name]);
}

void Menu::initFont(std::string font_name, std::string file_path)
{
	if (!this->fonts[font_name].loadFromFile(file_path))
	{
		std::cout << "ERROR::Menu::initFont::Failed to load " << file_path;
		std::cout << "\n";
	}
}

void Menu::initText(std::string text_name, std::string font_name)
{
	this->texts[text_name].setFont(this->fonts[font_name]);
	this->texts[text_name].setCharacterSize(50);
	this->texts[text_name].setFillColor(sf::Color::White);
	this->texts[text_name].setPosition(sf::Vector2f(10.f, 40.f));
	this->texts[text_name].setOutlineColor(sf::Color(0, 0, 0, 255)); //Black
	this->texts[text_name].setOutlineThickness(2.f);
	this->texts[text_name].setString("None");
}

//Constructors and Distructors
Menu::Menu()
{
	this->initVariables();
	this->initBackground();
	
	this->initTexture("menu_texture", "../Textures/Menu/menu.png");
	this->initSprite("menu", "menu_texture");
	this->initFont("menu_font", "../Fonts/PixellettersFull.ttf");
	this->initText("menu_play", "menu_font");
	this->initText("menu_restart", "menu_font");
	this->initText("menu_exit", "menu_font");
	
}

Menu::~Menu()
{

}

//Accessors
sf::FloatRect Menu::getSpriteBounds(std::string sprite_name)
{
	return this->sprites[sprite_name].getGlobalBounds();
}

sf::FloatRect Menu::getTextBounds(std::string text_name)
{
	return this->texts[text_name].getGlobalBounds();
}

const bool& Menu::isOpened() const
{
	return this->menuOpened;
}

//Modifires
void Menu::setOpened(const bool toggle)
{
	this->menuOpened = toggle;
}

void Menu::setBackgroundSize(const sf::Vector2f size)
{
	this->menuBackground.setSize(size);
}

void Menu::setBackgroundPosition(const sf::Vector2f pos)
{
	this->menuBackground.setPosition(pos);
}

void Menu::setBackgroundPosition(const float x, float y)
{
	this->menuBackground.setPosition(sf::Vector2f(x, y));
}

void Menu::setSpritePosition(std::string sprite_name, const sf::Vector2f pos)
{
	this->sprites[sprite_name].setPosition(pos);
}

void Menu::setSpritePosition(std::string sprite_name, const float x, const float y)
{
	this->sprites[sprite_name].setPosition(sf::Vector2f(x, y));
}

void Menu::setTextSize(std::string text_name, const unsigned int size)
{
	this->texts[text_name].setCharacterSize(size);
}

void Menu::setTextColor(std::string text_name, const sf::Color color)
{
	this->texts[text_name].setFillColor(color);
}

void Menu::setTextString(std::string text_name, const sf::String string)
{
	this->texts[text_name].setString(string);
}

void Menu::setTextPosition(std::string text_name, const sf::Vector2f pos)
{
	this->texts[text_name].setPosition(pos);
}

void Menu::setTextPosition(std::string text_name, const float x, const float y)
{
	this->texts[text_name].setPosition(sf::Vector2f(x, y));
}

//Functions
void Menu::update()
{

}

void Menu::renderBackground(sf::RenderTarget* target)
{
	target->draw(this->menuBackground);
}

void Menu::renderSprite(std::string sprite_name, sf::RenderTarget* target)
{
	target->draw(this->sprites[sprite_name]);
}

void Menu::renderText(std::string text_name, sf::RenderTarget* target)
{
	target->draw(this->texts[text_name]);
}

void Menu::render()
{
	//...
}