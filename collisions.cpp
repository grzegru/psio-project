#include "collisions.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>



Collisions::Collisions()
{
    if(!CollisionBuffer.loadFromFile("sounds/collisionsound.wav")){std::cout<<"Fail buffer load"<<std::endl;exit(0);}
    CollisionSound.setBuffer(CollisionBuffer);

}



bool Collisions::CheckCollision(sf::Sprite sprite1, sf::Sprite sprite2){               //kolizja ptaka z podlozem

    sprite1.setScale(0.070,0.070);

    sf::Rect<float> rect1 = sprite1.getGlobalBounds();
    sf::Rect<float> rect2 = sprite2.getGlobalBounds();

    if(rect1.intersects(rect2)){
        return true;

    }else{
        return false;
    }
}



bool Collisions::CheckCollision(sf::Sprite sprite1, sf::Sprite sprite2, sf::Sprite sprite3, bool isTransparency){  //kolizja ptaka z rurami

    sprite1.setScale(0.060,0.060);
    sf::Rect<float> rect1 = sprite1.getGlobalBounds();
    sf::Rect<float> rect2 = sprite2.getGlobalBounds();
    sf::Rect<float> rect3 = sprite3.getGlobalBounds();
    if (isTransparency) {
        return false;
    }
    else if((rect1.intersects(rect2))||(rect1.intersects(rect3))){
        return true;

    }else{
        return false;
    }
}

void Collisions::collisionSound(){
    CollisionSound.play();
}


