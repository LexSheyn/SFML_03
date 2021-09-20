#pragma once
class World
{
private:
	//Variables
	bool movingUp;
	bool movingDown;
	bool movingLeft;
	bool movingRight;

	//World
	sf::Texture texture;
	sf::Sprite sprite;

	//Private functions
	void initVariables();
	void initTexture();
	void initSprite();

public:
	//Constructors and Distructors
	World();
	virtual ~World();

	//Accessors
	const sf::FloatRect getBounds() const;
	const bool& getMovingUp() const;
	const bool& getMovingDown() const;
	const bool& getMovingLeft() const;
	const bool& getMovingRight() const;

	//Modifires
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);

	void setMovingUp(const bool value);
	void setMovingDown(const bool value);
	void setMovingLeft(const bool value);
	void setMovingRight(const bool value);

	//Functions	
	void move(const float dir_x, const float dir_y);

	//void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget& target);
};

