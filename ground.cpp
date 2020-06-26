#include "ground.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

Ground::Ground(int PosX, int PosY)
{
    if(!texture_ground.loadFromFile("textures_fonts/ground_grass.png")){std::cout<<"Fail ground load"<<std::endl;exit(0);}
    groundSprite.setTexture(texture_ground);
    texture_ground.setRepeated(true);
    groundSprite.setTextureRect(sf::IntRect(0,0,1000000,100));
    groundSprite.setPosition(PosX,PosY);
    groundSprite.setScale(0.8,0.8);


}

Ground::~Ground(){}

void Ground::Draw(sf::RenderWindow&window){
    window.draw(groundSprite);

}


void Ground::animate(sf::Time &elapsed, bool isBonus){
    if (isBonus) {
        ground_speed = -300;
    }
    else {
        ground_speed = -150;
    }
    groundSprite.move(ground_speed*elapsed.asSeconds(),0);
}



const sf::Sprite &Ground::GetSprite( ) const{
    return groundSprite;
}









