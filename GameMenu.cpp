#include "GameMenu.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

GameMenu::GameMenu()
{

  if(!texture_play_button.loadFromFile("textures_fonts/playbutton.png")){std::cout<<"Fail play_button load"<<std::endl;exit(0);}
  if(!texture_BirdMenu.loadFromFile("textures_fonts/ptak1.png")){std::cout<<"Fail birdMenu load"<<std::endl;exit(0);}
  if(!texture_TapToPlay.loadFromFile("textures_fonts/tap.png")){std::cout<<"Fail TaptoPlay load"<<std::endl;exit(0);}
  if(!texture_GetReady.loadFromFile("textures_fonts/getready.png")){std::cout<<"Fail GetReady load"<<std::endl;exit(0);}
  if(!texture_hand.loadFromFile("textures_fonts/hand.png")){std::cout<<"Fail hand load"<<std::endl;exit(0);}
  if(!texture_birdBlackWhite.loadFromFile("textures_fonts/ptakBlackWhite.png")){std::cout<<"Fail birdBlackWhite load"<<std::endl;exit(0);}
  if(!texture_Arrow.loadFromFile("textures_fonts/arrow.png")){std::cout<<"Fail Arrow load"<<std::endl;exit(0);}





  PlayButtonSprite.setTexture(texture_play_button);
  PlayButtonSprite.setScale(0.5,0.5);
  PlayButtonSprite.setPosition(170,300);


  texture_BirdMenu.setSmooth(true);
  BirdMenuSprite.setTexture(texture_BirdMenu);
  BirdMenuSprite.setScale(0.1,0.1);
  BirdMenuSprite.setPosition(50,300);

  TapToPlaySprite.setTexture(texture_TapToPlay);
  TapToPlaySprite.setPosition(260,350);
  TapToPlaySprite.setScale(0.6,0.6);

  GetReadySprite.setTexture(texture_GetReady);
  GetReadySprite.setPosition(70,130);
  GetReadySprite.setScale(0.9,0.9);

  HandSprite.setTexture(texture_hand);
  HandSprite.setPosition(230 , 400);
  HandSprite.setScale(1.5,1.5 );

  BirdBlackWhiteSprite.setTexture(texture_birdBlackWhite);
  BirdBlackWhiteSprite.setScale(0.075,0.075);
  BirdBlackWhiteSprite.setPosition(220, 280);

  ArrowSprite.setTexture(texture_Arrow);
  ArrowSprite.setScale(0.5 , 0.5);
  ArrowSprite.setPosition(220,330);

  if (!GameMusicBuffer.loadFromFile("sounds/soundtrack.wav")) { std::cout << "Fail buffer load" << std::endl; exit(0); }
  GameMusic.setBuffer(GameMusicBuffer);

}


void GameMenu::Draw(sf::RenderWindow&window){     //rysowanie do ekranu startowego
    window.draw(PlayButtonSprite);
    window.draw(BirdMenuSprite);

}

void GameMenu::Draw2(sf::RenderWindow&window){      //rysowanie do ekranu przed gra
    window.draw(TapToPlaySprite);
    window.draw(GetReadySprite);
    window.draw(HandSprite);
    window.draw(BirdBlackWhiteSprite);
    window.draw(ArrowSprite);


}
void GameMenu::Animate(bool isBonus) {
    isBonusOn = isBonus;
    if (isBonusOn) {
        GameMusic.setPitch(2);
    }
    else {
        GameMusic.setPitch(1);
    }
}
void GameMenu::clickPlay() {
    GameMusic.setLoop(true);
    GameMusic.play();

}




