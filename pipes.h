#ifndef PIPES_H
#define PIPES_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>



class Pipes: public sf::Sprite
{
public:
    Pipes(int PosX, int PosY, int Distance);
    ~Pipes();

    void Draw(sf::RenderWindow&window);
    void animate(sf::Time &elapsed);


    float speed=-150;
    int PosX=700;
    int PosY=800;




    //tekstury i sprity
    sf::Texture texture_pipe_up, texture_pipe_down;
    sf::Sprite pipe_up, pipe_down;

};

#endif // PIPES_H
