#include <ncurses.h>

#include <iostream>
#include <string>
#include "init.hpp"
#include "sprite.hpp"


int main() {
  initCurses();
  try {
    std::string ballFile = "Sprites/ball.sprt";
    Sprite ball(ballFile, 1, 1);
    ball.putAt(1,1);
    refresh();
    getch();
    exitCurses();
  }

  catch(std::runtime_error err) {
    exitCurses();
    std::cout << err.what() << std::endl;
    return 1;
  }
  return 0;
}
