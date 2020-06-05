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
    void click(sf::Event &event,sf::RenderWindow&window, bool gamestart);




    sf::Texture texture_menu, texture_play_button, texture_BirdMenu;
    sf::Sprite MenuSprite, PlayButtonSprite, BirdMenuSprite;


};

#endif // GAMEMENU_H
