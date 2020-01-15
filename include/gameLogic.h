#ifndef LOGIC_H_
#define LOGIC_H_

#include <SFML/Graphics.hpp>



class gameLogic
{
  public:
  gameLogic(); //constructor
  void collision();
  void update(sf::RenderWindow &window);
  void score(sf::RenderWindow &window);


};

#endif /* LOGIC_H_ */
