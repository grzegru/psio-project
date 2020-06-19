#include "Points.h"

Points::Points()
{



    if(!font.loadFromFile("textures_fonts/font.ttf")){std::cout<<"fail font loaded"<<std::endl; exit(0);}
    _scoreTx.setFont(font);
    _scoreTx.setString("0");
    _scoreTx.setCharacterSize(128);
    _scoreTx.setFillColor(sf::Color::White);
    _scoreTx.setOrigin(_scoreTx.getGlobalBounds().width/2,_scoreTx.getGlobalBounds().height/2);
    _scoreTx.setPosition(250,200);
    _scoreTx.setScale(0.6,0.6);

    if(!_pointsBuffer.loadFromFile("sounds/pointsound.wav")){std::cout<<"fail buffer loaded"<<std::endl; exit(0);}
    _pointsSound.setBuffer(_pointsBuffer);




}



void Points::addpoints(int _amount_of_points){
    _amount_of_points++;

}



void Points::Draw( sf::RenderWindow &window ){
    window.draw( _scoreTx );
}



void Points::updateScore( int score ){
    _scoreTx.setString( std::to_string( score ));

}



void Points::PointsSound(){
    _pointsSound.play();
}
