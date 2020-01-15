#include <SFML/Graphics.hpp>
#include "Paddle.h"


int main(int argc, char** argv){
{
  // create main window
  sf::RenderWindow window(sf::VideoMode(800,600,32), "Hello World - SFML");

  // start main loop
  while(window.isOpen())
  {


    // clear screen and fill with blue
    window.clear(sf::Color::Blue);

    // display
    window.display();
  }


}
return 0;
}
