#include "Paddle.h"
#include "Ball.h"
#include "Constants.h"
#include <SFML/Graphics.hpp>




Paddle::Paddle(bool player)
 {
   paddle.setSize({ 10, 80});
   paddle.setFillColor(sf::Color::White);
   paddle.setOrigin(5,40);
   if (player){
     pos = {10,height/2};
   }
   else{
     pos = {width-10,height/2};
   }
 }

void Paddle::update(sf::RenderWindow &window)
{
  paddle.setPosition(pos);
  window.draw(paddle);
}

void Paddle::move(bool player)
{
  if (player)
  {
 if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)||sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
   pos.y = pos.y -1.5;
 if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)||sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
   pos.y = pos.y +1.5;
 }

 if (pos.y <= 40)
  pos.y = pos.y +2;
  if (pos.y >=555)
  pos.y = pos.y -2;
}
