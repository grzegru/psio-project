#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "pipes.h"


class GameOver: public sf::Sprite
{
public:
    GameOver();





    sf::Texture texture_Game_Over, texture_ScoreBoard, texture_BronzeMedal, texture_SilverMedal, texture_GoldMedal;
    sf::Sprite Game_over, ScoreBoard, BronzeMedal, SilverMedal, GoldMedal;

    void PipeCollision(sf::RenderWindow &window, bool isGameOver, int points);
    void Draw(sf::RenderWindow &window);




};

#endif // GAMEOVER_H
