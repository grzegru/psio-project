#ifndef BONUS_H
#define BONUS_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>




class bonus
{

public:
    bonus();

    void draw(sf::RenderWindow &window);

    void spawn(float x);

    void animate(sf::RenderWindow& window, double ms, float x);

    void harvest();

    sf::Sprite getSprite();

private:
    sf::Texture bonusTexture;

    sf::Sprite bonusSprite;

    double _time = 0;
    int _speed = -150;
    bool _isExist = false;
};

#endif // BONUS_H
