#include "Graphics.h"

// Constructor / Destructor
Graphics::Graphics()
{

    // Initialize window pointers to null
    m_menuWindow = NULL;
    m_playWindow = NULL;
    m_rulesWindow = NULL;
    m_winWindow = NULL;
    
    // Call init functions
    InitFonts();
    InitTexts();
    InitButtons();
    InitTextures();

}
Graphics::~Graphics()
{
}

// Main Menu loop
// Displays the main menu until a button is pressed, returns which button.
int Graphics::RunMenuLoop()
{

    int selection = 0;

    m_menuWindow = new sf::RenderWindow(sf::VideoMode(1600, 800), "SFML Battleship");

    // Graphics loop
    while (m_menuWindow->isOpen())
    {
        sf::Event event;
        while (m_menuWindow->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_menuWindow->close();
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (getPlayButton().getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        // Play button was clicked
                        //Game.playGame();
                        m_menuWindow->close();
                        selection = 1;
                    }
                    else if (getRulesButton().getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        // Rules button was clicked
                        //RulesScreen();
                        m_menuWindow->close();
                        selection = 2;
                    }
                    else if (getExitButton().getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        // Exit button was clicked
                        // Close program
                        m_menuWindow->close();
                        selection = 3;
                            
                    }
                }
                break;
            default:
                break;
            }
        }

        m_menuWindow->clear();
        DrawMainMenu();
        m_menuWindow->display();
    }

    delete m_menuWindow;
    m_menuWindow = NULL;

    return selection;

}

// // Initialization functions
void Graphics::InitFonts()
{
    if (!m_font.loadFromFile("Fonts/PixellettersFull.ttf"))
    {
        cout << "[ERROR] - Failed to load font file" << "\n";
    }
}
void Graphics::InitTexts()
{
    float heightButton = 50.f;
    float widthButton = 200.f;
    sf::Color colorText = sf::Color::White;
    sf::Color colorOutlineText = sf::Color::Black;

    m_titleText.setFont(m_font);
    m_titleText.setString("BATTLESHIP");
    m_titleText.setCharacterSize(300);
    m_titleText.setFillColor(colorText);
    m_titleText.setOutlineThickness(5.f);
    m_titleText.setOutlineColor(sf::Color::Black);
    m_titleText.setPosition(180.f, -80.f);

    m_playText.setFont(m_font);
    m_playText.setString("Play");
    m_playText.setCharacterSize(100);
    m_playText.setFillColor(colorText);
    m_playText.setOutlineThickness(2.f);
    m_playText.setOutlineColor(sf::Color::Black);
    m_playText.setPosition(775.f, 265.f);

    m_rulesText.setFont(m_font);
    m_rulesText.setString("Rules");
    m_rulesText.setCharacterSize(100);
    m_rulesText.setFillColor(colorText);
    m_rulesText.setOutlineThickness(2.f);
    m_rulesText.setOutlineColor(sf::Color::Black);
    m_rulesText.setPosition(750.f, 425.f);

    m_exitText.setFont(m_font);
    m_exitText.setString("Exit");
    m_exitText.setCharacterSize(100);
    m_exitText.setFillColor(colorText);
    m_exitText.setOutlineThickness(2.f);
    m_exitText.setOutlineColor(sf::Color::Black);
    m_exitText.setPosition(775.f, 585.f);
}
void Graphics::InitButtons()
{
    float heightButton = 100.f;
    float widthButton = 300.f;
    float outlineThicknessButton = 5.f;
    sf::Color colorButton = sf::Color(50, 150, 230);
    sf::Color colorOutline = sf::Color::Black;

    m_playButton.setSize(sf::Vector2f(widthButton, heightButton));
    m_playButton.setFillColor(colorButton);
    m_playButton.setOutlineThickness(outlineThicknessButton);
    m_playButton.setOutlineColor(colorOutline);
    m_playButton.setPosition(690.f, 290.f);

    m_rulesButton.setSize(sf::Vector2f(widthButton, heightButton));
    m_rulesButton.setFillColor(colorButton);
    m_rulesButton.setOutlineThickness(outlineThicknessButton);
    m_rulesButton.setOutlineColor(colorOutline);
    m_rulesButton.setPosition(690.f, 450.f);

    m_exitButton.setSize(sf::Vector2f(widthButton, heightButton));
    m_exitButton.setFillColor(colorButton);
    m_exitButton.setOutlineThickness(outlineThicknessButton);
    m_exitButton.setOutlineColor(colorOutline);
    m_exitButton.setPosition(690.f, 610.f);
}
void Graphics::InitTextures()
{
    if (!m_menuBackgroundTexture.loadFromFile("Textures/MenuTexture.png"))
    {
        cout << "[ERROR] - Failed to load 'Textures/MenuTexture.png'" << "\n";
    }
    if (!m_playBackgroundTexture.loadFromFile("Textures/PlayTexture.png"))
    {
        cout << "[ERROR] - Failed to load texture file" << "\n";
    }
    if (!m_rulesBackgroundTexture.loadFromFile("Textures/MenuTexture.png"))
    {
        cout << "[ERROR] - Failed to load 'Textures/MenuTexture.png'" << "\n";
    }
}

// Main menu functions
void Graphics::DrawMainMenu()
{
    // Background sprite
    sf::Sprite menuSprite;
    menuSprite.setScale(1.5, 1.5);
    menuSprite.setTexture(getMenuTexture());

    m_menuWindow->draw(menuSprite);
    m_menuWindow->draw(getPlayButton());
    m_menuWindow->draw(getRulesButton());
    m_menuWindow->draw(getExitButton());
    m_menuWindow->draw(getTitleText());
    m_menuWindow->draw(getPlayButtonText());
    m_menuWindow->draw(getRulesButtonText());
    m_menuWindow->draw(getExitButtonText());

    HighlightOnHoverButton();
}

// Provides feedback when the mouse is hovering over a button
void Graphics::HighlightOnHoverButton()
{
    sf::Color colorHoverButton = sf::Color(255, 255, 255, 100); // orange color

    // Check if mouse is over play button
    if (m_playButton.getGlobalBounds().contains(sf::Mouse::getPosition(*m_menuWindow).x, sf::Mouse::getPosition(*m_menuWindow).y))
    {
        m_playButton.setFillColor(colorHoverButton); // set new color when mouse is over the button
    }
    else
    {
        m_playButton.setFillColor(sf::Color(50, 150, 230));
    }

    // Check if mouse is over rules button
    if (m_rulesButton.getGlobalBounds().contains(sf::Mouse::getPosition(*m_menuWindow).x, sf::Mouse::getPosition(*m_menuWindow).y))
    {
        m_rulesButton.setFillColor(colorHoverButton);
    }
    else
    {
        m_rulesButton.setFillColor(sf::Color(50, 150, 230));
    }

    // Check if mouse is over exit button
    if (m_exitButton.getGlobalBounds().contains(sf::Mouse::getPosition(*m_menuWindow).x, sf::Mouse::getPosition(*m_menuWindow).y))
    {
        m_exitButton.setFillColor(colorHoverButton);
    }
    else
    {
        m_exitButton.setFillColor(sf::Color(50, 150, 230));
    }
}

// Play Screen
void Graphics::ShootScreen(Player& p1, int &x, int& y)
{
    // If main menu is open, it will be closed
    if (m_menuWindow != NULL)
    {
        m_menuWindow->close();
        delete m_menuWindow;
        m_menuWindow = NULL;
    }

    // Create the play window if not already open
    if (m_playWindow == NULL) {

        m_playWindow = new sf::RenderWindow(sf::VideoMode(1600, 800), "SFML Battleship");

    }

    // Play background sprite
    sf::Sprite playSprite;
    playSprite.setScale(0.6, 0.6);
    playSprite.setPosition(0, 0);
    playSprite.setTexture(getPlayTexture());

    // Create side panel
    sf::RectangleShape panelLeft;
    panelLeft.setSize(sf::Vector2f(300.f, 760.f));
    panelLeft.setFillColor(sf::Color(0, 50, 150, 125));
    panelLeft.setOutlineColor(sf::Color::Black);
    panelLeft.setOutlineThickness(10);
    panelLeft.setPosition(20.f, 20.f);

    // Create side panel's text
    sf::Text leftText;
    leftText.setFont(m_font);
    leftText.setCharacterSize(70);
    leftText.setFillColor(sf::Color::White);
    leftText.setOutlineThickness(3.f);
    leftText.setOutlineColor(sf::Color::Black);
    leftText.setPosition(65.f, 130.f);

    // Build a string with player stats, put it into the Text object
    std::ostringstream oss;
    oss << "Hits: " << p1.getHits() << "\n\n\nMisses: " << p1.getMisses() << "\n\n\nShots: " << p1.getShots();
    leftText.setString(oss.str());

    // Play Graphics loop
    while (m_playWindow->isOpen())
    {
        sf::Event event;
        while (m_playWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_playWindow->close();
            }
        }

        // If the window has been closed it'll return to the main menu.
        if (!m_playWindow->isOpen()) {

            delete m_playWindow;
            m_playWindow = NULL;

            // Flag value
            x = -1;
            return;

        }

        // Init to flag values
        int row = -1;
        int column = -1;

        // If user is clicking on a square, find it and give its grid coordinates.
        p1.getRadar().CheckCell(*m_playWindow, row, column);

        // If coordinates were found
        if (row != -1 && column != -1) {

            //return them by pointer
            x = row;
            y = column;

            return;

        }

        // Clear window and draw play background
        m_playWindow->clear(sf::Color::Blue);
        m_playWindow->draw(playSprite);

        // Draw side panel
        m_playWindow->draw(panelLeft);

        // Draw side panel's text
        m_playWindow->draw(leftText);

        // Set grid position and draw grid
        p1.getBoard().SetGridPosition(400, 150);
        p1.getRadar().SetGridPosition(1000, 150);

        // Draws grid1 to the window
        p1.getBoard().DrawGrid(*m_playWindow);

        // Draws grid2 to the window
        p1.getRadar().DrawGrid(*m_playWindow);

        // Display m_playWindow
        m_playWindow->display();
    }

    // Reinitialize the pointer
    delete m_playWindow;
    m_playWindow = NULL;

}

// Rules functions
void Graphics::RulesScreen()
{
    // Kills any existing rules windows, if such a bug occurs
    if (m_rulesWindow != NULL)
    {
        m_rulesWindow->close();
        delete m_rulesWindow;
        m_rulesWindow = NULL;
    }

    // Declare a new window to render for the rules
    m_rulesWindow = new sf::RenderWindow(sf::VideoMode(1600, 800), "SFML Battleship");

    // Background sprite from main menu
    sf::Sprite backgroundSprite;
    backgroundSprite.setScale(1.5, 1.5);
    backgroundSprite.setTexture(getRulesTexture());

    // Rectangle shape for rules to be displayed on
    sf::RectangleShape rulesRectangle;
    rulesRectangle.setSize(sf::Vector2f(1400, 700));
    rulesRectangle.setFillColor(sf::Color(50, 150, 230));
    rulesRectangle.setOutlineThickness(5.f);
    rulesRectangle.setOutlineColor(sf::Color::Black);
    rulesRectangle.setPosition(100.f, 50.f);

    // Rules texts
    m_rulesTitle.setFont(m_font);
    m_rulesTitle.setString("How to Play");
    m_rulesTitle.setCharacterSize(75);
    m_rulesTitle.setFillColor(sf::Color::White);
    m_rulesTitle.setOutlineThickness(2.f);
    m_rulesTitle.setOutlineColor(sf::Color::Black);
    m_rulesTitle.setPosition(600.f, 50.f);

    m_rules.setFont(m_font);
    m_rules.setString(
        "\n[ 1 ] Ships are placed randomly onto a 10x10 grid\n\n"
        "[ 2 ] Click a square to shoot at the opponent's grid\n\n"
        "[ 3 ] Hits will be marked as RED\n\n"
        "[ 4 ] Misses will be marked as WHITE\n\n"
        "[ 5 ] Sink the opponent's ships before they sink yours!"
    );
    m_rules.setCharacterSize(60);
    m_rules.setFillColor(sf::Color::White);
    m_rules.setOutlineThickness(2.f);
    m_rules.setOutlineColor(sf::Color::Black);
    m_rules.setPosition(150.f, 120.f);

    // Rule Graphics loop
    while (m_rulesWindow->isOpen())
    {
        sf::Event event;
        while (m_rulesWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_rulesWindow->close();
            }
        }
        m_rulesWindow->draw(backgroundSprite);
        m_rulesWindow->draw(rulesRectangle);
        m_rulesWindow->draw(getRulesTitle());
        m_rulesWindow->draw(getRules());
        m_rulesWindow->display();
    }

    // Reinitialize the pointer
    delete m_rulesWindow;
    m_rulesWindow = NULL;

}

// Splash screen on win
void Graphics::WinScreen(Player& p1, bool playerWin)
{
    // Kills any existing win windows, if such a bug occurs
    if (m_winWindow != NULL)
    {
        m_winWindow->close();
        delete m_winWindow;
        m_winWindow = NULL;
    }

    // Declare a new window to render for the rules
    m_winWindow = new sf::RenderWindow(sf::VideoMode(1600, 800), "SFML Battleship");

    // Background sprite from main menu
    sf::Sprite backgroundSprite;
    backgroundSprite.setScale(1.5, 1.5);
    backgroundSprite.setTexture(getRulesTexture());

    // Rectangle shape for rules to be displayed on
    sf::RectangleShape rulesRectangle;
    rulesRectangle.setSize(sf::Vector2f(1400, 700));
    rulesRectangle.setFillColor(sf::Color(50, 150, 230));
    rulesRectangle.setOutlineThickness(5.f);
    rulesRectangle.setOutlineColor(sf::Color::Black);
    rulesRectangle.setPosition(100.f, 50.f);

    // Text settings
    sf::Text winText;
    winText.setFont(m_font);
    winText.setCharacterSize(150);
    winText.setFillColor(sf::Color::White);
    winText.setOutlineThickness(4.f);
    winText.setOutlineColor(sf::Color::Black);
    winText.setPosition(575.f, 275.f);

    // Changes depending on whether the player actually won or not
    if (playerWin) {

        winText.setString("You Win!");

    }
    else {

        winText.setString("You Lose...");

    }

    sf::Text statsText;
    statsText.setFont(m_font);
    statsText.setCharacterSize(75);
    statsText.setFillColor(sf::Color::White);
    statsText.setOutlineThickness(2.f);
    statsText.setOutlineColor(sf::Color::Black);
    statsText.setPosition(650.f, 450.f);

    // Build a string with player stats, put it into the Text object
    std::ostringstream oss;
    oss << "Hits: " << p1.getHits() << "\nMisses: " << p1.getMisses() << "\nTotal shots: " << p1.getShots();
    statsText.setString(oss.str());

    // Win Graphics loop
    while (m_winWindow->isOpen())
    {
        sf::Event event;
        while (m_winWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_winWindow->close();
            }
        }
        m_winWindow->draw(backgroundSprite);
        m_winWindow->draw(rulesRectangle);
        m_winWindow->draw(winText);
        m_winWindow->draw(statsText);
        m_winWindow->display();
    }

    // Reinitialize the pointer
    delete m_winWindow;
    m_winWindow = NULL;

}

// Accessors
const sf::RectangleShape& Graphics::getPlayButton()
{
    return m_playButton;
}
const sf::RectangleShape& Graphics::getRulesButton()
{
    return m_rulesButton;
}
const sf::RectangleShape& Graphics::getExitButton()
{
    return m_exitButton;
}

const sf::Texture& Graphics::getMenuTexture()
{
    return m_menuBackgroundTexture;
}
const sf::Texture& Graphics::getPlayTexture()
{
    return m_playBackgroundTexture;
}
const sf::Texture& Graphics::getRulesTexture()
{
    return m_rulesBackgroundTexture;
}

const sf::Text& Graphics::getTitleText()
{
    return m_titleText;
}
const sf::Text& Graphics::getPlayButtonText()
{
    return m_playText;
}
const sf::Text& Graphics::getRulesButtonText()
{
    return m_rulesText;
}
const sf::Text& Graphics::getExitButtonText()
{
    return m_exitText;
}
const sf::Text& Graphics::getRulesTitle()
{
    return m_rulesTitle;
}
const sf::Text& Graphics::getRules()
{
    return m_rules;
}