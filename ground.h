#ifndef GROUND_H
#define GROUND_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>




class Ground: public sf::Sprite
{
public:
    Ground(int PosX, int PosY);
    ~Ground();


    void Draw(sf::RenderWindow &window);

    void animate(sf::Time &elapsed);

    int PosX=0;
    int PosY=700;
    int speed=-150;




    sf::Texture texture_ground;
    sf::Sprite ground;


};

#endif // GROUND_H
