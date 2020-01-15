#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Constants.h"
#include "Ball.h"
#include "gameLogic.h"



gameLogic logic;




int main(int argc, char** argv){

  //create the game window

  sf::RenderWindow window(sf::VideoMode(width, height), "Game window", sf::Style::Close);


  window.setFramerateLimit(200);
  sf::Clock clock;





  while(window.isOpen()){
    sf::Event Event;
    while(window.pollEvent(Event))
    {

      switch(Event.type){
        case sf::Event::Closed:
            window.close();
            break;

      }
    }

    window.clear(sf::Color::Black);
    

    logic.score(window);
    logic.collision();
    logic.update(window);
    window.display();
  }
  return 0;
}
