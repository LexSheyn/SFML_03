#pragma once

class Bullet
{
private:
	//Objects
	sf::Sprite sprite;
	sf::Vector2f direction;

	//Variables
	float moveSpeed;

	//Private functions
	void initVariables();

public:
	//Constructors and Distructors
	Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float move_speed);
	virtual ~Bullet();

	//Accessors
	const sf::FloatRect getBounds() const;

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};

