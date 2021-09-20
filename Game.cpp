#include "stdafx.h"
#include "Game.h"

//Private fuinctions
void Game::initWindow()
{
	//Loading icon (.PNG only)
	if (!this->icon.loadFromFile("../Textures/ship_icon.png"))
	{
		std::cout << "ERROR::Game::initWindow::Failed to load icon";
	}

	this->framerateLimit = 144;

	this->resolution = 0; // Unused

	this->window = new sf::RenderWindow(
		sf::VideoMode(1120, 630),
		"Game 03: Lords of space",
		sf::Style::Close | sf::Style::Titlebar);

	this->window->setFramerateLimit(this->framerateLimit);

	this->window->setVerticalSyncEnabled(false);

	this->window->setIcon(this->icon.getSize().x, this->icon.getSize().y, this->icon.getPixelsPtr());
}

void Game::initVariables()
{
	this->movingUp = false;
	this->movingX = false;
	this->gameOver = false;

	this->mouseHeld = false;
	this->escHeld = false;
	this->textHighlight = false;
}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();

	int queue_num = rand() % 3 + 1;
	switch (queue_num)
	{
	case 1:	
		this->textures["BULLET"]->loadFromFile("../Textures/Projectile/projectile_-180.png");
		break;
	case 2:	
		this->textures["BULLET"]->loadFromFile("../Textures/Projectile/projectile_-160.png");
		break;
	case 3:	
		this->textures["BULLET"]->loadFromFile("../Textures/Projectile/projectile_-140.png");
		break;
	}
}

void Game::initMenu()
{
	this->menu = new Menu();
	//Sprite
	this->menu->setSpritePosition("menu",
		this->window->getSize().x / 2.f - this->menu->getSpriteBounds("menu").width / 2.f,
		this->window->getSize().y / 2.f - this->menu->getSpriteBounds("menu").height / 2.f);

	//Play
	this->menu->setTextString("menu_play", "PLAY");
	this->menu->setTextPosition("menu_play",
		this->menu->getSpriteBounds("menu").width * 0.55f - this->menu->getTextBounds("menu_play").width / 2.f,
		this->menu->getSpriteBounds("menu").height * 0.47f - this->menu->getTextBounds("menu_play").height / 2.f);
	
	//Restart
	this->menu->setTextString("menu_restart", "RESTART");
	this->menu->setTextPosition("menu_restart",
		this->menu->getSpriteBounds("menu").width * 0.55f - this->menu->getTextBounds("menu_restart").width / 2.f,
		this->menu->getSpriteBounds("menu").height * 0.47f - this->menu->getTextBounds("menu_restart").height / 2.f);
	
	//Exit
	this->menu->setTextString("menu_exit", "EXIT");
	this->menu->setTextPosition("menu_exit",
		this->menu->getSpriteBounds("menu").width * 0.55f - this->menu->getTextBounds("menu_exit").width / 2.f,
		this->menu->getSpriteBounds("menu").height * 0.57f - this->menu->getTextBounds("menu_exit").height / 2.f);

	//Background
	this->menu->setBackgroundSize(sf::Vector2f(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)));
	this->menu->setBackgroundPosition(0.f, 0.f);
}

void Game::initGUI()
{
	//Load font
	if (!this->font.loadFromFile("../Fonts/PixellettersFull.ttf"))
	{
		std::cout << "ERROR::INITGUI::Failed to load font" << "\n";
	}

	//Init point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(24);
	this->pointText.setFillColor(sf::Color(255, 255, 255, 255)); //White
	this->pointText.setPosition(sf::Vector2f(10.f, 40.f));
	this->pointText.setOutlineColor(sf::Color(0, 0, 0, 255)); //Black
	this->pointText.setOutlineThickness(1.f);
	this->pointText.setString("None");

	//Init game over text
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(100);
	this->gameOverText.setFillColor(sf::Color(255, 0, 0, 255)); //Red
	this->gameOverText.setOutlineColor(sf::Color(0, 0, 0, 255)); //Black
	this->gameOverText.setOutlineThickness(2.f);
	this->gameOverText.setString("GAME OVER");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.5f - this->gameOverText.getGlobalBounds().height / 2.f);

	//Init game over background
	this->gameOverBackground.setSize(sf::Vector2f(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)));
	this->gameOverBackground.setFillColor(sf::Color(0, 0, 0, 150));
	this->gameOverBackground.setPosition(0.f, 0.f);

	//Init player GUI
	this->playerHpBarBack.setSize(sf::Vector2f(200.f, 20.f));
	this->playerHpBarBack.setPosition(sf::Vector2f(10.f, 20.f));

	this->playerHpBar = this->playerHpBarBack;

	this->playerHpBarBack.setOutlineColor(sf::Color(0, 0, 0, 255)); //Black
	this->playerHpBarBack.setOutlineThickness(1.f);
	this->playerHpBarBack.setFillColor(sf::Color(200, 0, 0, 255)); //Red

	this->playerHpBar.setFillColor(sf::Color(0, 220, 0, 255)); //Green

	this->hpText.setFont(this->font);
	this->hpText.setCharacterSize(24);
	this->hpText.setFillColor(sf::Color::White);
	this->hpText.setOutlineColor(sf::Color::Black);
	this->hpText.setOutlineThickness(1.f);
	this->hpText.setString("100|100");
	//this->hpText.setOrigin(sf::Vector2f(this->hpText.getGlobalBounds().width / 2.f, this->hpText.getGlobalBounds().height / 2.f));
	this->hpText.setPosition(
		sf::Vector2f(
			(this->playerHpBarBack.getGlobalBounds().left + this->playerHpBarBack.getGlobalBounds().width) / 2.f - this->hpText.getGlobalBounds().width / 2.f,
			(this->playerHpBarBack.getGlobalBounds().top + this->playerHpBarBack.getGlobalBounds().height) / 2.f - this->hpText.getGlobalBounds().height / 2.f));
}

void Game::initWorld()
{
	this->world = new World();
	this->world->setPosition(
		this->window->getSize().x / 2.f - this->world->getBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->world->getBounds().height / 2.f);
}

void Game::initSystems()
{
	this->points = 0;
}

void Game::initSpeaker()
{
	this->speaker = new Speaker();
}

void Game::initPlayer()
{
	this->player = new Player();
	this->player->setPosition(
		this->window->getSize().x / 2.f - this->player->getBounds().width / 2.f,
		this->window->getSize().y / 2.f + this->player->getBounds().height);
}

void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

//Constructors and Distructors
Game::Game()
{
	this->initWindow();
	this->initVariables();
	this->initTextures();
	this->initMenu();
	this->initGUI();
	this->initWorld();
	this->initSystems();

	this->initSpeaker();
	this->initPlayer();
	this->initEnemies();

	this->speaker->setSoundsVolume(25.f);
}

Game::~Game()
{
	//Delete window
	delete this->window;

	//Delete menu
	delete this->menu;

	//Delete world
	delete this->world;

	//Delete speaker
	delete this->speaker;

	//Delete player
	delete this->player;
	
	//Delete textures
	for (auto &i : this->textures)
	{
		delete i.second;
	}

	//Delete bullets
	for (auto *i : this->bullets)
	{
		delete i;
	}

	//Delete enemies
	for (auto *i : this->enemies)
	{
		delete i;
	}
}

//Functions
void Game::run()
{
	while (this->window->isOpen())
	{
		//std::cout << this->menu->isOpened() << "\n";

		this->deltaTime = this->clock.restart().asSeconds();

		this->updatePollEvents();
		this->updateMenu();

		if (this->menu->isOpened() != true)
		{
			if (this->player->getHp() != 0)
			{
				this->update();
			}
			else
			{
				this->player->setPlayerTexture("dead");
				if (this->gameOver == false)
				{
					this->speaker->stopMusic("1");
					this->speaker->stopMusic("2");
					this->speaker->stopMusic("3");
					this->speaker->playSound("game_over");
					this->gameOver = true;
				}
			}
		}
		this->render();
	}
}

void Game::updatePollEvents()
{
	//Poll events
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}
	}
}

void Game::updateMousePosition()
{
	/*
		@return void

		Updates the mouse positions
		- Mouse positions relative to window (Vector2i)
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateMenu()
{
	this->updateMousePosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		if (this->escHeld == false)
		{
			this->escHeld = true;

			this->speaker->playSound("menu_open");

			if (this->menu->isOpened() == false)
			{
				this->menu->setOpened(true);
			}
			else if (this->menu->isOpened() == true)
			{
				this->menu->setOpened(false);
			}
		}
	}
	else
	{
		this->escHeld = false;
	}

	if (this->menu->isOpened() == true)
	{
		if (this->menu->getTextBounds("menu_restart").contains(this->mousePosView))
		{
			if (this->textHighlight == false)
			{
				this->textHighlight = true;
				this->speaker->playSound("menu_highlight");
				this->menu->setTextColor("menu_restart", sf::Color::Red);
			}
		}
		else if (this->menu->getTextBounds("menu_exit").contains(this->mousePosView))
		{
			if (this->textHighlight == false)
			{
				this->textHighlight = true;
				this->speaker->playSound("menu_highlight");
				this->menu->setTextColor("menu_exit", sf::Color::Red);
			}
		}
		else
		{
			this->textHighlight = false;
			this->menu->setTextColor("menu_restart", sf::Color::White);
			this->menu->setTextColor("menu_exit", sf::Color::White);
		}

		//Check if clicked upon
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (this->mouseHeld == false)
			{
				this->mouseHeld = true;

				if (this->menu->getTextBounds("menu_restart").contains(this->mousePosView))
				{
					this->speaker->playSound("menu_click");

					//Resetting player hp, points, update GUI
					this->player->setHp(100);
					this->points = 0;
					this->updateGUI();

					//Deleting all enemies and bullets
					this->enemies.clear();
					this->bullets.clear();

					//Resetting player sprite and position
					this->player->setPlayerTexture("idle");
					this->player->setPosition(
						this->window->getSize().x / 2.f - this->player->getBounds().width / 2.f,
						this->window->getSize().y / 2.f + this->player->getBounds().height);

					//Resetting background position
					this->world->setPosition(
						this->window->getSize().x / 2.f - this->world->getBounds().width / 2.f,
						this->window->getSize().y / 2.f - this->world->getBounds().height / 2.f);

					//Resetting game over variable
					this->gameOver = false;

					//Sleep game for 250 milliseconds
					std::this_thread::sleep_for(std::chrono::milliseconds(250));

					//Closing menu
					this->menu->setOpened(false);

					//System echo
					std::cout << "RESTART pressed\n";
				}
				else if (this->menu->getTextBounds("menu_exit").contains(this->mousePosView))
				{
					this->speaker->playSound("menu_click");
					std::this_thread::sleep_for(std::chrono::milliseconds(250));
					this->window->close();
				}
			}
		}
		else
		{
			this->mouseHeld = false;
		}
	}
}

void Game::updateInput()
{
	this->player->setPlayerTexture("idle");
	
	//Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->player->setPlayerTexture("left");
		this->player->move(-1.f, 0.f);

		// - Left
		if (this->player->getBounds().left > 0.f)
		{
			this->world->move(-1.f, 0.f);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->player->setPlayerTexture("right");
		this->player->move(1.f, 0.f);

		// - Right
		if (this->player->getBounds().left + this->player->getBounds().width < window->getSize().x)
		{
			this->world->move(1.f, 0.f);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->player->setPlayerTexture("up");
		this->movingUp = true;

		std::cout << "Moving Up: " << this->movingUp;
		std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b";

		this->player->move(0.f, -1.f);

		// - Top
		if (this->player->getBounds().top > 0.f)
		{
			this->world->move(0.f, -1.f);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->movingUp = false;

		std::cout << "Moving Up: " << this->movingUp;
		std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b";

		this->player->move(0.f, 1.f);
		
		if (this->player->getBounds().top + this->player->getBounds().height < window->getSize().y)
		{
			this->world->move(0.f, 1.f);
		}
	}

	if ((sf::Mouse::isButtonPressed(sf::Mouse::Left) or sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) and this->player->canAttack())
	{
		this->speaker->playSound("blaster");

		if (this->movingUp == false)
		{
			this->bullets.push_back(new Bullet(this->textures["BULLET"],
				(this->player->getPos().x - 5.f) + ((this->player->getBounds().width / 2.f)),
				this->player->getPos().y,
				0.f,
				-1.f,
				4.f));
		}
		else if (this->movingUp == true)
		{
			this->bullets.push_back(new Bullet(this->textures["BULLET"],
				(this->player->getPos().x - 5.f) + ((this->player->getBounds().width / 2.f)),
				this->player->getPos().y + this->player->getMoveSpeed(),
				0.f,
				-1.f,
				4.f + this->player->getMoveSpeed()));
		}
	}
}

void Game::updateGUI()
{
	//Updating points
	std::stringstream ss_points;

	ss_points << "Points: "
		<< this->points
		<< "\n";

	this->pointText.setString(ss_points.str());

	//Updating hp number
	std::stringstream ss_hp;

	ss_hp << this->player->getHp()
		<< "/"
		<< this->player->getHpMax()
		<< "\n";

	this->hpText.setString(ss_hp.str());

	//Updating hp bar
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();

	this->playerHpBar.setSize(sf::Vector2f(200.f * hpPercent, this->playerHpBarBack.getSize().y));
}

void Game::updateWorld()
{

}

void Game::updateCollision()
{
	//Player world collision
	// - Left
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}// - Right
	else if (this->player->getBounds().left + this->player->getBounds().width > window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}
	// - Top
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}// - Bottom
	else if (this->player->getBounds().top + this->player->getBounds().height > window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
	}
}

void Game::updateBullets()
{
	unsigned counter = 0;

	for (auto* bullet : this->bullets)
	{
		bullet->update();

		//Bullet culling (top of the screen)
		if (bullet->getBounds().top + bullet->getBounds().height <= 0.f)
		{
			//Delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);

			//std::cout << this->bullets.size() << "\n";
		}
		++counter;
	}
}

void Game::updateEnemies()
{
	//Spawning
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 50.f, -100.f));

		this->spawnTimer = 0.f;

		for (auto* enemy : this->enemies)
		{
			//Enemies world collision
			// - Left
			if (enemy->getBounds().left < 40.f)
			{
				enemy->setPosition(40.f, enemy->getBounds().top);
			}// - Right
			else if (enemy->getBounds().left + enemy->getBounds().width > (window->getSize().x) - 40)
			{
				enemy->setPosition((this->window->getSize().x - enemy->getBounds().width) - 40.f, enemy->getBounds().top);
			}
		}
	}

	this->spawnTimer += 0.5f;

	//Update
	unsigned counter = 0;

	for (auto *enemy : this->enemies)
	{
		enemy->update();

		//Enemies culling (bottom of the screen)
		if (enemy->getBounds().top > this->window->getSize().y)
		{
			//Delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);

			//std::cout << this->enemies.size() << "\n";

		}//Enemy player collision
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			//Delete enemy
			if (this->enemies.at(counter)->getType() == "heal")
			{
				this->speaker->playSound("heal");
			}
			else
			{
				this->speaker->playRandomSound("player_impact");
			}
			
			this->player->loseHp(this->enemies.at(counter)->getDamage());
			this->points += this->enemies.at(counter)->getPoints();
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}

		++counter;
	}
}

void Game::updateCombat()
{
	for (unsigned i = 0; i < enemies.size(); ++i)
	{
		bool enemy_deleted = false;

		for (unsigned j = 0; j < this->bullets.size() && enemy_deleted == false; j++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[j]->getBounds()))
			{
				if (this->enemies[i]->getType() == "enemy")
				{
					this->points += this->enemies[i]->getPoints();

					delete this->enemies[i];
					this->enemies.erase(this->enemies.begin() + i);

					delete this->bullets[j];
					this->bullets.erase(this->bullets.begin() + j);

					enemy_deleted = true;
				}
			}
		}
	}
}

void Game::updateMusic()
{
	int queue_num = rand() % 3 + 1;
	switch (queue_num)
	{
	case 1:
		if (this->speaker->getMusicStatus("1") != sf::SoundSource::Playing
			and this->speaker->getMusicStatus("2") != sf::SoundSource::Playing
			and this->speaker->getMusicStatus("3") != sf::SoundSource::Playing
			and queue_num == 1)
		{
			this->speaker->openMusic("1", "../Sounds/Music/main_1.ogg");
			this->speaker->setMusicVolume("1", 50.f);
			this->speaker->setMusicLoop("1", false);
			this->speaker->playMusic("1");
		}
		break;
	case 2:
		if (this->speaker->getMusicStatus("1") != sf::SoundSource::Playing
			and this->speaker->getMusicStatus("2") != sf::SoundSource::Playing
			and this->speaker->getMusicStatus("3") != sf::SoundSource::Playing
			and queue_num == 2)
		{
			this->speaker->openMusic("2", "../Sounds/Music/main_2.ogg");
			this->speaker->setMusicVolume("2", 50.f);
			this->speaker->setMusicLoop("2", false);
			this->speaker->playMusic("2");
		}
		break;
	case 3:
		if (this->speaker->getMusicStatus("1") != sf::SoundSource::Playing
			and this->speaker->getMusicStatus("2") != sf::SoundSource::Playing
			and this->speaker->getMusicStatus("3") != sf::SoundSource::Playing
			and queue_num == 3)
		{
			this->speaker->openMusic("3", "../Sounds/Music/main_3.ogg");
			this->speaker->setMusicVolume("3", 50.f);
			this->speaker->setMusicLoop("3", false);
			this->speaker->playMusic("3");
		}
		break;
	}
}

void Game::update()
{
	this->updateInput();	
	this->updateCollision();
	this->updateBullets();
	this->updateEnemies();
	this->updateCombat();
	this->player->update(this->window);
	this->updateGUI();
	this->updateWorld();

	this->updateMusic();
}

void Game::renderWorld()
{
	//this->window->draw(this->worldBackground);	
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
	this->window->draw(this->hpText);
}

void Game::render()
{
	//Clear frame
	this->window->clear();

	//Draw background
	//this->renderWorld();
	this->world->render(*this->window);

	//Draw bullets		
	for (auto *bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	//Draw enemies
	for (auto *enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	//Draw player
	this->player->render(*this->window);

	//Draw GAME OVER background
	if (this->player->getHp() == 0)
	{
		this->window->draw(this->gameOverBackground);
	}

	//Draw GUI
	this->renderGUI();

	//Draw GAME OVER text
	if (this->player->getHp() == 0)
	{
		this->window->draw(this->gameOverText);
	}

	//Draw menu
	if (this->menu->isOpened() == true)
	{
		this->menu->renderBackground(this->window);
		this->menu->renderSprite("menu", this->window);
		//this->menu->renderText("menu_play", this->window);
		this->menu->renderText("menu_restart", this->window);
		this->menu->renderText("menu_exit", this->window);
	}

	//Display drawn frame
	this->window->display();
}