#include "bonus.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

bonus::bonus() {
    bonusTexture.loadFromFile("textures_fonts/Apple.png");
    bonusSprite.setTexture(bonusTexture);
    bonusSprite.setOrigin(bonusTexture.getSize().x / 2.0, bonusTexture.getSize().y / 2.0);
    bonusSprite.setScale(2, 2);

}

void bonus::draw(sf::RenderWindow &window) {
    window.draw(bonusSprite);
}

void bonus::spawn(float x) {

    if ((_time >= 14.0)&&(!(_isExist))) {    //time>= 12  // im mniejszy czas tym czesciej sie pokazuje

        int random = rand() % 300 + 100;
        bonusSprite.setPosition(x+225, random);
        _isExist = true;
        _time = 0.0;
    }

}

void bonus::animate(sf::RenderWindow &window, double ms, float x) {
    _time += ms;
    spawn(x);
    bonusSprite.move(_speed * ms, 0);

    if (bonusSprite.getPosition().x < 0) {
        _isExist = false;
    }
    if (_isExist) {
        draw(window);
    }
}

sf::Sprite bonus::getSprite() {
    return bonusSprite;
}

void bonus::harvest() {
    bonusSprite.setPosition(-100, 300);
    _isExist = false;
}
