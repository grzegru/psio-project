#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>




class Background
{
public:
    Background();
    ~Background(){}

    void draw(sf::RenderWindow&window);

private:
    sf::Texture texture_background;
    sf::Sprite background;

};

#endif // BACKGROUND_H
