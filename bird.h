#ifndef BIRD_H
#define BIRD_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "ground.h"
#include "pipes.h"



class Bird: public sf::Sprite
{
public:
    Bird(int PosX, int PosY);

    void Draw(sf::RenderWindow&window);


    void animate();

    void click();

    void Update( sf::Time &elapsed);

    void birdfalling(sf::Time &elapsed);

    const sf::Sprite &GetSprite( ) const;

private:

    int PosX=100;
    int PosY=400;
    int gravitation=200;
    int fly=-200;
    int fall_speed=200;
    int _ground_height=638;




    sf::Texture texture_bird1,texture_bird2,texture_bird3,texture_bird4;
    sf::Sprite bird;
    std::vector<sf::Texture> _animationBirdFrame;



    unsigned int _animationBirdIterator;

    sf::Clock _clock;

    sf::Clock _moveClock;
    sf::Clock _move2Clock;

    float angle;



    enum BirdState {STILL, FALLING, FLYING};   //typ wyliczeniowy , bedzie okreslac w jakim stanie jest aktualnie ptak
    BirdState birdState;


};

#endif // BIRD_H
