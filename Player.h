#pragma once
class Player
{
private:
	//Objects
	std::map<std::string, sf::Texture> textures;
	//sf::Texture texture;
	sf::Sprite sprite;

	//Variables
	float moveSpeed;

	float attackCooldownMax;
	float attackCooldown;

	int hpMax;
	int hp;

	//Private functions
	void initVariables();
	void initTexture();
	void initSprite();

public:	
	//Constructors and Distructors
	Player();
	virtual ~Player();

	//Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const float& getMoveSpeed() const;
	const int& getHpMax() const;
	const int& getHp() const;
	sf::Texture& getTexture();

	//Modifires
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void getHp(const int value);
	void loseHp(const int value);
	void setPlayerTexture(std::string texture_name);

	//Functions	
	void move(const float dir_x, const float dir_y);
	const bool canAttack();
	
	//void updateWindowBoundsCollision(const sf::RenderTarget* target);

	void updateHp();
	void upadateAttack();
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget& target);
};

