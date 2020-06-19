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


    void Draw(sf::RenderWindow &window, int _points);

    void HighScore(sf::RenderWindow &window, int _points);

    sf::Sprite PlayAgainButton, ExitButton;



private:
    sf::Texture texture_Game_Over, texture_ScoreBoard, texture_BronzeMedal, texture_SilverMedal, texture_GoldMedal, texture_playAgain, texture_exit;
    sf::Sprite Game_over, ScoreBoard, BronzeMedal, SilverMedal, GoldMedal;// PlayAgainButton, ExitButton;

    sf::Clock _clock;

    sf::Text _scoreTx, _highscoreTx;
    sf::Font font;

    int _highscore;




};

#endif // GAMEOVER_H
