#ifndef PADDLE_H_
#define PADDLE_H_

#include <SFML/Graphics.hpp>


class Paddle
{
  public:
  Paddle(bool player);
  sf::Vector2f pos;
  sf::RectangleShape paddle;
  void move(bool player);
  void update(sf::RenderWindow &window);
  bool player;


};

#endif
