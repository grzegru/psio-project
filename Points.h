#ifndef POINTS_H
#define POINTS_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>


class Points
{
public:
    Points();


    bool CheckPoints(sf::Sprite sprite1, sf::Sprite sprite2 );

    void addpoints(int _amount_of_points);

    void Draw(sf::RenderWindow &window);

    void updateScore(int score);

    void PointsSound();


private:



    sf::Text _scoreTx;
    sf::Font font;

    sf::SoundBuffer _pointsBuffer;
    sf::Sound _pointsSound;




};

#endif // POINTS_H
