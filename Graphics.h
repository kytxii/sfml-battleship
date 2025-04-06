#pragma once

#include "Libraries.h"
#include "Grid.h"
#include "Ship.h"
#include "Player.h"

class Graphics
{
public:
	// Constructor / Destructor
	Graphics();
	~Graphics();

	// Menu Graphics loop, returns selection
	int RunMenuLoop();

	// Initialization functions
	void InitFonts();
	void InitTexts();
	void InitButtons();
	void InitTextures();

	// Main menu functions
	void DrawMainMenu();
	void HighlightOnHoverButton();

	// Play Graphics functions
	void ShootScreen(Player& p1, int& x, int& y);
	void DrawShips(sf::RenderWindow& window, Carrier& carrier, Battleship& battleship, Cruiser& cruiser, Submarine& submarine, Destroyer& destroyer);

	// Splash Screens
	void RulesScreen();
	void WinScreen(Player& p1, bool playerWin);

	// Accessors
	const sf::RectangleShape& getPlayButton();
	const sf::RectangleShape& getRulesButton();
	const sf::RectangleShape& getExitButton();

	const sf::Texture& getMenuTexture();
	const sf::Texture& getPlayTexture();
	const sf::Texture& getRulesTexture();

	const sf::Text& getTitleText();
	const sf::Text& getPlayButtonText();
	const sf::Text& getRulesButtonText();
	const sf::Text& getExitButtonText();
	const sf::Text& getRulesTitle();
	const sf::Text& getRules();

private:
	// Window pointers
	// They're pointers so that the windows can be reconstructed multiple times.
	sf::RenderWindow* m_menuWindow;
	sf::RenderWindow* m_playWindow;
	sf::RenderWindow* m_rulesWindow;
	sf::RenderWindow* m_winWindow;

	// Buttons
	sf::RectangleShape m_playButton;
	sf::RectangleShape m_rulesButton;
	sf::RectangleShape m_exitButton;

	// Textures
	sf::Texture m_menuBackgroundTexture;
	sf::Texture m_playBackgroundTexture;
	sf::Texture m_rulesBackgroundTexture;

	// Font
	sf::Font m_font;

	// Text variables
	sf::Text m_titleText;
	sf::Text m_playText;
	sf::Text m_rulesText;
	sf::Text m_exitText;
	sf::Text m_rulesTitle;
	sf::Text m_rules;

};