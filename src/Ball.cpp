#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Constants.h"



Ball::Ball()
{
  ball.setRadius(8);
  ball.setFillColor(sf::Color::White);
  pos = {width/2, height/2};
  direction={ 1,1};
}



void Ball::move()
{
  pos.x += direction.x;
  pos.y += direction.y;
  if(pos.y > 580)
    direction.y = direction.y * -1; //bounce off if you hit the top and bottom
  if(pos.y < 5)
      direction.y = direction.y * -1;
}

void Ball::update(sf::RenderWindow &window)
{
  ball.setPosition(pos);
  window.draw(ball);
}
