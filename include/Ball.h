#ifndef BALL_H_
#define BALL_H_

#include <SFML/Graphics.hpp>

class Ball
{
public:
  Ball();
  sf::Vector2f pos;
  sf::CircleShape ball;
  void update(sf::RenderWindow &window);
  void move();
  sf::Vector2f direction;





};



#endif
