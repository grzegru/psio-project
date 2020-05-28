#ifndef COLLISIONS_H
#define COLLISIONS_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>




class Collisions
{
public:
    Collisions();

    bool CheckCollision(sf::Sprite sprite1, sf::Sprite sprite2);
    bool CheckCollision(sf::Sprite sprite1, sf::Sprite sprite2, sf::Sprite sprite3);








};

#endif // COLLISIONS_H
