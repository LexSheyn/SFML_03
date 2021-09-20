#pragma once

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Speaker.h"
#include "World.h"
#include "Menu.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::Image icon;
	unsigned framerateLimit;
	unsigned resolution;

	//Vadiables
	bool movingUp;
	bool movingX;
	bool gameOver;

	bool mouseHeld;
	bool escHeld;
	bool textHighlight;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Menu
	Menu* menu;

	//GUI
	sf::Font font;
	sf::Text pointText;
	sf::Text hpText;
	sf::Text gameOverText;
	sf::RectangleShape gameOverBackground;

	//World
	World* world;

	//Systems
	unsigned points;

	//Speaker
	Speaker* speaker;

	//Player
	Player* player;
	
	//Player GUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//Enemies
	float spawnTimerMax;
	float spawnTimer;
	std::vector<Enemy*> enemies;

	//Private fuinctions
	void initWindow();
	void initVariables();
	void initTextures();
	void initMenu();
	void initGUI();
	void initWorld();
	void initSystems();
	void initSpeaker();
	void initPlayer();
	void initEnemies();

public:
	//Delta time
	float deltaTime = 0.f;
	sf::Clock clock;

	//Constructors and Distructors
	Game();
	virtual ~Game();

	//Functions
	void run();

	void updatePollEvents();
	void updateMousePosition();
	void updateMenu();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateBullets();
	void updateEnemies();
	void updateCombat();
	void updateMusic();
	void update();

	void renderWorld();
	void renderGUI();
	void render();
};

