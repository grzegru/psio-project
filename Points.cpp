#include "Points.h"

Points::Points()
{

}


bool Points::CheckPoints(sf::Sprite sprite1, sf::Sprite sprite2){
    float posSprite1=sprite1.getPosition().x;
    float posSprite2=sprite2.getPosition().x;

    if(posSprite1>posSprite2){
        return true;
    }else{
        return false;
    }

}
