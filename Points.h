#ifndef POINTS_H
#define POINTS_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>


class Points
{
public:
    Points();


    bool CheckPoints(sf::Sprite sprite1, sf::Sprite sprite2 );
};

#endif // POINTS_H
