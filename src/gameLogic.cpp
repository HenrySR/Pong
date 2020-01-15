#include "Ball.h"
#include "Paddle.h"
#include "gameLogic.h"
#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <random>


Paddle player(1);
Paddle ai(0);
Ball ball;
int aiscore1 = 0;
int playerscore1 = 0;



gameLogic::gameLogic()
{


}

 void gameLogic::update(sf::RenderWindow &window)
 {
   if(!window.hasFocus()){
     sf::sleep(sf::seconds(2));
     player.update(window);//lets you see objects while game is paused
     ai.update(window);
    ball.update(window);
   }
   else{
   player.move(1);
   ball.move();
   player.update(window);
   ai.update(window);
  ball.update(window);
  if (aiscore1 >10){
    sf::Text text;
    sf::Font aerial;
    aerial.loadFromFile("aerial.ttf");
    text.setFont(aerial);
    text.setString("\t\t You Lose.\n Would You Like to Play Again?\n \t\t Y/N");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setPosition(width/6 ,height/4);
    window.draw(text);
    ball.pos = {width/2,height/2};
    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Minus)) //Non-functional game Difficulty slider
      //gameSpeed -= .1;
    //  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Plus))
    //    gameSpeed += .1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::N))
      window.close();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y)){
      aiscore1 = 0;
     playerscore1 = 0;
    }
  }
  if (playerscore1 >10){
    sf::Text text;
    sf::Font aerial;
    aerial.loadFromFile("aerial.ttf");
    text.setFont(aerial);
    text.setString("\t\t You Win.\n Would You Like to Play Again?\n  \t\t Y/N");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(width/6 ,height/4);
    window.draw(text);
    ball.pos = {width/2,height/2};
    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Minus)) //Non-functional game Difficulty slider
      //gameSpeed -= .1;
    //  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Plus))
    //    gameSpeed += .1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::N))
      window.close();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
    {
      aiscore1 = 0;
     playerscore1 = 0;
    }

  }
}

 }

 void gameLogic::collision()
 {
   float v1 = ((rand() % 10)-5);
   v1= v1/70;
   float v2 =((rand()%4)-2);
   if((ball.pos.y < player.pos.y +40) && (ball.pos.y > player.pos.y -40) && (ball.pos.x<10) ){
     ball.direction.y =ball.direction.y+ (1+v1);//randomness on paddle hit to reflect at a slightly different angle
    ball.direction.x = ball.direction.x* -1.05;//ball speeds up slowly each time it hits a paddle
  };
    if((ball.pos.y > ai.pos.y -40)&& (ball.pos.y < ai.pos.y +40) &&(ball.pos.x>760) ){
    ball.direction.y =ball.direction.y+ (1+v1);//randomness on paddle hit to reflect at a slightly different angle
     ball.direction.x = ball.direction.x* -1.05;
   };
   if (ball.pos.x<0){
     ball.direction= {1.3,v2};
    ball.pos = {width/2,height/2};
    aiscore1 =  aiscore1 + 1;
  };
  if (ball.pos.x>800){
    ball.direction= {-1.3,v2};
   ball.pos = {width/2,height/2};
   playerscore1 = playerscore1 + 1;
 };
   if((ball.pos.x>width/2)&&(ai.pos.y <ball.pos.y)&&!(ai.pos.y >555))//ai moves its paddle towards the paddle if the ball is on its side of the screen
    ai.pos.y = ai.pos.y +1.5;
    //ai.pos.y = ai.pos.y +gameSpeed;
    if((ball.pos.x>width/2)&&(ai.pos.y >ball.pos.y)&&!(ai.pos.y <40))
     ai.pos.y = ai.pos.y -1.5;
     //ai.pos.y = ai.pos.y -gameSpeed;
 }
void gameLogic::score(sf::RenderWindow &window){
  sf::Text aiscore;
  sf::Font aerial;
  aerial.loadFromFile("aerial.ttf");
  aiscore.setFont(aerial);
  aiscore.setCharacterSize(25);
  aiscore.setString(std::to_string(aiscore1));
  aiscore.setFillColor(sf::Color::White);
  aiscore.setPosition(width*.70,0);
  sf::Text playerscore;
  playerscore.setFont(aerial);
  playerscore.setCharacterSize(25);
  playerscore.setString(std::to_string(playerscore1));
  playerscore.setFillColor(sf::Color::White);
  playerscore.setPosition(width*.40,0);
  window.draw(aiscore);
  window.draw(playerscore);
}
