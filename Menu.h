#pragma once
class Menu
{
private:
	//Objects
	sf::RectangleShape menuBackground;
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::Text> texts;
	std::map<std::string, sf::Sprite> sprites;

	//Variables
	bool menuOpened;

	//Private functions
	void initVariables();
	void initBackground();
	void initTexture(std::string texture_name, std::string file_path);
	void initSprite(std::string sprite_name, std::string texture_name);
	void initFont(std::string font_name, std::string file_path);
	void initText(std::string text_name, std::string font_name);

public:
	//Constructors and Distructors
	Menu();
	virtual ~Menu();

	//Public variables
	bool mOpen = false;

	//Accessors
	sf::FloatRect getSpriteBounds(std::string sprite_name);
	sf::FloatRect getTextBounds(std::string text_name);
	const bool& isOpened() const;

	//Modifires
	void setOpened(const bool toggle);

	void setBackgroundSize(const sf::Vector2f size);
	void setBackgroundPosition(const sf::Vector2f pos);
	void setBackgroundPosition(const float x, float y);

	void setSpritePosition(std::string sprite_name, const sf::Vector2f pos);
	void setSpritePosition(std::string sprite_name, const float x, const float y);

	void setTextSize(std::string text_name, const unsigned int size);
	void setTextColor(std::string text_name, const sf::Color color);
	void setTextString(std::string text_name, const sf::String string);

	void setTextPosition(std::string text_name, const sf::Vector2f pos);
	void setTextPosition(std::string text_name , const float x, const float y);

	//Functions
	void update();

	void renderBackground(sf::RenderTarget* target);
	void renderSprite(std::string sprite_name, sf::RenderTarget* target);
	void renderText(std::string text_name, sf::RenderTarget* target);
	void render();
};

