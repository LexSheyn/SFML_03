#include "stdafx.h"
#include "Enemy.h"

//Private functions
void Enemy::initVariables()
{
	this->pointCount = (rand() % 8 + 3); // min = 3, max = 10
	this->type		 = "enemy";
	this->moveSpeed  = static_cast<float>(this->pointCount)/5.f;
	this->hpMax		 = static_cast<int>(this->pointCount);
	this->hp		 = hpMax;
	this->damage	 = this->pointCount;
	this->points	 = this->pointCount;
}

void Enemy::initShape()
{
	int rand_type = rand() % 100 + 1;

	this->shape.setRadius(this->pointCount + 20.f);
	this->shape.setPointCount(this->pointCount);

	if (rand_type <= 10)
	{
		this->type = "heal";
		this->shape.setFillColor(sf::Color(100, 255, 100, 255));
		this->damage = -static_cast<int>(this->pointCount);
		this->points = 0;
		this->moveSpeed = 1.f;
		this->shape.setOutlineColor(sf::Color::Black);
		this->shape.setOutlineThickness(4.f);
	}
	else
	{
		this->type = "enemy";
		this->shape.setFillColor(sf::Color(255, rand() % 255, 0, 255));
		this->damage = this->pointCount * 2;
		this->points = this->pointCount;
		this->moveSpeed = static_cast<float>(this->pointCount) / 5.f;
		this->shape.setOutlineColor(sf::Color::Black);
		this->shape.setOutlineThickness(1.f);
	}
}

//Constructors and Distructors
Enemy::Enemy(float pos_x, float pos_y)
{	
	this->initVariables();
	this->initShape();
	this->shape.setPosition(pos_x, pos_y);
}

Enemy::~Enemy()
{

}

//Accessors
const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

const std::string& Enemy::getType() const
{
	return this->type;
}

//Modifires
void Enemy::setPosition(const sf::Vector2f pos)
{
	this->shape.setPosition(pos);
}

void Enemy::setPosition(const float x, const float y)
{
	this->shape.setPosition(x, y);
}

void Enemy::move(const float value)
{
	this->shape.move(0.f, this->moveSpeed + value);
}

//Funstions
void Enemy::update()
{
	this->shape.move(0.f, this->moveSpeed);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}