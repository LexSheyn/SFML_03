#include "stdafx.h"
#include "Player.h"

//Private functions
void Player::initVariables()
{
	this->moveSpeed = 4.f;

	this->attackCooldownMax = 20.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 100; //100 for game, 1 for tests
	this->hp = hpMax;
}

void Player::initTexture()
{
	//Load texture from file
	//int queue_num = rand() % 3 + 1;
	int queue_num = 1;
	switch (queue_num)
	{
	case 1:
		if (!this->textures["idle"].loadFromFile("../Textures/Ship/Minus/ship_-180.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load " << "???" << "\n";
		}
		if (!this->textures["left"].loadFromFile("../Textures/Ship/Minus/ship_-180_left.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load " << "???" << "\n";
		}
		if (!this->textures["right"].loadFromFile("../Textures/Ship/Minus/ship_-180_right.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load " << "???" << "\n";
		}
		if (!this->textures["up"].loadFromFile("../Textures/Ship/Minus/ship_-180_up.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load " << "???" << "\n";
		}
		if (!this->textures["dead"].loadFromFile("../Textures/Ship/Minus/ship_-180_n_gb.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load " << "???" << "\n";
		}
		break;
	case 2:
		if (!this->textures["idle"].loadFromFile("../Textures/Ship/Minus/ship_-160.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load " << "???" << "\n";
		}
		if (!this->textures["left"].loadFromFile("../Textures/Ship/Minus/ship_-160_left.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load " << "???" << "\n";
		}
		if (!this->textures["right"].loadFromFile("../Textures/Ship/Minus/ship_-160_right.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load " << "???" << "\n";
		}
		break;
	case 3:
		if (!this->textures["idle"].loadFromFile("../Textures/Ship/Minus/ship_-140.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load " << "???" << "\n";
		}
		if (!this->textures["left"].loadFromFile("../Textures/Ship/Minus/ship_-140_left.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load " << "???" << "\n";
		}
		if (!this->textures["right"].loadFromFile("../Textures/Ship/Minus/ship_-140_right.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load " << "???" << "\n";
		}
		break;
	}
}

void Player::initSprite()
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->textures["idle"]);
	this->sprite.setPosition(sf::Vector2f(10.f, 10.f));

	//Resize the sprite
	this->sprite.scale(0.5f, 0.5f);
}

//Constructors and Distructors
Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

//Accessors
const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const float& Player::getMoveSpeed() const
{
	return this->moveSpeed;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

const int& Player::getHp() const
{
	return this->hp;
}

sf::Texture& Player::getTexture()
{
	return this->textures["idle"];
}

//Modifires
void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::getHp(const int value)
{
	this->hp += value;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
}

void Player::setPlayerTexture(std::string texture_name)
{
	this->sprite.setTexture(textures[texture_name]);
}

//Functions
void Player::move(const float dir_x, const float dir_y)
{
	this->sprite.move(this->moveSpeed * dir_x, this->moveSpeed * dir_y);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}
/*
void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	//Left
	if (this->sprite.getGlobalBounds().left <= 0.f)
	{
		this->sprite.setPosition(0.f, this->sprite.getGlobalBounds().top);
	}

	//Right
	if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= target->getSize().x)
	{
		this->sprite.setPosition(target->getSize().x - this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().top);
	}

	//Top
	if (this->sprite.getGlobalBounds().top <= 0.f)
	{
		this->sprite.setPosition(this->sprite.getGlobalBounds().left, 0.f);
	}

	//Bottom
	if (this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height >= target->getSize().y)
	{
		this->sprite.setPosition(this->sprite.getGlobalBounds().left, target->getSize().y - this->sprite.getGlobalBounds().height);
	}
}
*/
void Player::updateHp()
{
	if (this->hp > this->hpMax)
	{
		this->hp = this->hpMax;
	}
	else if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void Player::upadateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 1.f;
	}
}

void Player::update(const sf::RenderTarget* target)
{
	//this->updateWindowBoundsCollision(target);
	this->updateHp();
	this->upadateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}