#include "stdafx.h"
#include "World.h"

//Private functions
void World::initVariables()
{
	this->movingUp = false;
	this->movingDown = false;
	this->movingLeft = false;
	this->movingRight = false;
}

void World::initTexture()
{
	//Load texture from file
	if (!this->texture.loadFromFile("../Textures/Background/background_1920x1080.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load " << "???" << "\n";
	}
}

void World::initSprite()
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(sf::Vector2f(10.f, 10.f));
}

//Constructors and Distructors
World::World()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

World::~World()
{

}

//Accessors
const sf::FloatRect World::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const bool& World::getMovingUp() const
{
	return this->movingUp;
}

const bool& World::getMovingDown() const
{
	return this->movingDown;
}

const bool& World::getMovingLeft() const
{
	return this->movingLeft;
}

const bool& World::getMovingRight() const
{
	return this->movingRight;
}


//Modifires
void World::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void World::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void World::setMovingUp(const bool value)
{
	this->movingUp = value;
}

void World::setMovingDown(const bool value)
{
	this->movingDown = value;
}

void World::setMovingLeft(const bool value)
{
	this->movingLeft = value;
}

void World::setMovingRight(const bool value)
{
	this->movingRight = value;
}

//Functions	
void World::move(const float dir_x, const float dir_y)
{
	this->sprite.move(dir_x, dir_y);
}
/*
void World::update(const sf::RenderTarget* target)
{

}
*/
void World::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}