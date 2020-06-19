#ifndef PIPES_H
#define PIPES_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>



class Pipes: public sf::Sprite
{
public:
    Pipes();
    ~Pipes();



    void animate(sf::Time &elapsed);

    bool CheckPoints(float BirdPos);

    const sf::Sprite &GetSprite() const;

    const sf::Sprite &GetSprite2() const;

    void Draw(sf::RenderWindow&window);

    void setPipe1position();

    void setPipe2position();

private:


    float speed=-150;
    int _posX=600;
    int _posY=380;
    int _distance=300;
    int _difference=770;



    //tekstury i sprity
    sf::Texture texture_pipe_up, texture_pipe_down;
    sf::Sprite pipe_upSprite, pipe_downSprite;

};

#endif // PIPES_H
