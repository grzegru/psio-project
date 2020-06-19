#ifndef GAMEMENU_H
#define GAMEMENU_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>


class GameMenu
{
public:
    GameMenu();

    void Draw(sf::RenderWindow &window);

    void Draw2(sf::RenderWindow &window);

    void click(bool _isGameStart, bool _isGameOver, bool _isTaped);

    void clickPlay(sf::RenderWindow &window, bool _isGameStart);





    sf::Texture texture_menu, texture_play_button, texture_BirdMenu, texture_TapToPlay, texture_GetReady, texture_hand, texture_birdBlackWhite, texture_Arrow;
    sf::Sprite MenuSprite, PlayButtonSprite, BirdMenuSprite, TapToPlaySprite, GetReadySprite, HandSprite, BirdBlackWhiteSprite, ArrowSprite;
private:

    sf::Clock _clock;






};

#endif // GAMEMENU_H
