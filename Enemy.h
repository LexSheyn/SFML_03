#pragma once

class Enemy
{
private:
	//Objects
	sf::CircleShape shape;

	//Variables
	unsigned pointCount;
	std::string type;
	float moveSpeed;
	int hpMax;
	int hp;
	int damage;
	int points;

	//Private functions
	void initVariables();
	void initShape();

public:
	//Constructors and Distructors
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	//Accessors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;
	const std::string& getType() const;

	//Modifires
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void move(const float value);

	//Funstions
	void update();
	void render(sf::RenderTarget* target);
};

