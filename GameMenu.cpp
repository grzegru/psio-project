#include "GameMenu.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

GameMenu::GameMenu()
{
  //if(!texture_menu.loadFromFile("C:/Users/Grzechu/Pictures/ptak1.png")){std::cout<<"Fail menu_tx load"<<std::endl;exit(0);}
  if(!texture_play_button.loadFromFile("C:/Users/Grzechu/Pictures/playbutton.png")){std::cout<<"Fail button_tx load"<<std::endl;exit(0);}
  if(!texture_BirdMenu.loadFromFile("C:/Users/Grzechu/Pictures/ptak1.png")){std::cout<<"Fail button_tx load"<<std::endl;exit(0);}


  //MenuSprite.setTexture(texture_menu);
  PlayButtonSprite.setTexture(texture_play_button);
  PlayButtonSprite.setScale(0.5,0.5);
  PlayButtonSprite.setPosition(170,350);


  texture_BirdMenu.setSmooth(true);
  BirdMenuSprite.setTexture(texture_BirdMenu);
  BirdMenuSprite.setScale(0.1,0.1);
  BirdMenuSprite.setPosition(50,350);

}


void GameMenu::Draw(sf::RenderWindow&window){
    //window.draw(MenuSprite);
    window.draw(PlayButtonSprite);
    window.draw(BirdMenuSprite);

}


void GameMenu::click(sf::Event &event,sf::RenderWindow&window, bool gamestart){
    if(event.type==sf::Event::MouseButtonPressed){
        if(event.mouseButton.button==sf::Mouse::Left){
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if(PlayButtonSprite.getGlobalBounds().contains(mousePos.x,mousePos.y)){
                gamestart=true;
                std::cout<<"klikniete";
            }
        }
    }
}


