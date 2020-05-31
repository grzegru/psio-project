#include "collisions.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>



Collisions::Collisions()
{

}

bool Collisions::CheckCollision(sf::Sprite sprite1, sf::Sprite sprite2){

    sprite1.setScale(0.063,0.063);         //dla dokladnosci kolizji ptaka z ziemia

    sf::Rect<float> rect1 = sprite1.getGlobalBounds();
    sf::Rect<float> rect2 = sprite2.getGlobalBounds();

    if(rect1.intersects(rect2)){
        return true;
    }else{
        return false;
    }
}



bool Collisions::CheckCollision(sf::Sprite sprite1, sf::Sprite sprite2, sf::Sprite sprite3){

    sprite1.setScale(0.063,0.063);         //dla dokladnosci kolizji ptaka z rurami

    sf::Rect<float> rect1 = sprite1.getGlobalBounds();
    sf::Rect<float> rect2 = sprite2.getGlobalBounds();
    sf::Rect<float> rect3 = sprite3.getGlobalBounds();

    if((rect1.intersects(rect2))||(rect1.intersects(rect3))){
        return true;
    }else{
        return false;
    }
}

