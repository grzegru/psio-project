#include "ground.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

Ground::Ground(int PosX, int PosY)
{
    if(!texture_ground.loadFromFile("C:/Users/Grzechu/Pictures/ground_grass.png")){std::cout<<"Fail ground load"<<std::endl;exit(0);}
    ground.setTexture(texture_ground);
    texture_ground.setRepeated(true);
    ground.setTextureRect(sf::IntRect(0,0,1000000,100));
    ground.setPosition(PosX,PosY);
    ground.setScale(0.8,0.8);


}

Ground::~Ground(){}

void Ground::Draw(sf::RenderWindow&window){
    window.draw(ground);

}


void Ground::animate(sf::Time &elapsed){
    ground.move(speed*elapsed.asSeconds(),0);
}














