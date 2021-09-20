#include "stdafx.h"
#include "Bullet.h"

//Private functions
void Bullet::initVariables()
{
	this->moveSpeed = 0.f;
}

//Constructors and Distructors
Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float move_speed)
{
	this->initVariables();

	this->sprite.setTexture(*texture);

	this->sprite.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->moveSpeed = move_speed;
}

Bullet::~Bullet()
{

}

//Accessors
const sf::FloatRect Bullet::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

//Functions
void Bullet::update()
{
	//Movement
	this->sprite.move(this->moveSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}