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
    void addpoints(int _amount_of_points);
    void Draw(sf::RenderWindow &window);
    void updateScore(int score);


private:

    sf::Sprite number_zero,number_one, number_two, number_three,number_four,number_five,number_six,number_seven,number_eight,number_nine;
    sf::Texture texture_number_zero,texture_number_one,texture_number_two,texture_number_three,texture_number_four,texture_number_five,
                texture_number_six,texture_number_seven,texture_number_eight,texture_number_nine;


    sf::Text _scoreTx;
    sf::Font font;


};

#endif // POINTS_H
