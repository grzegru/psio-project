#include "background.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>



Background::Background()
{


    if(!texture_background.loadFromFile("textures_fonts/background.png")){std::cout<<"Fail background load"<<std::endl;exit(0);}
    _backgroundSprite.setTexture(texture_background);
    _backgroundSprite.setTextureRect(sf::IntRect(0,0,550,750));
    texture_background.setRepeated(true);

}


void Background::draw(sf::RenderWindow&window){
    window.draw(_backgroundSprite);}
