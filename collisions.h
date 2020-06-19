#ifndef COLLISIONS_H
#define COLLISIONS_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>




class Collisions
{
public:
    Collisions();

    bool CheckCollision(sf::Sprite sprite1, sf::Sprite sprite2);

    bool CheckCollision(sf::Sprite sprite1, sf::Sprite sprite2, sf::Sprite sprite3);

    void collisionSound();

private:

    sf::SoundBuffer CollisionBuffer;
    sf::Sound CollisionSound;








};

#endif // COLLISIONS_H
