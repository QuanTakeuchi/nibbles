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

    Coor init, scrLimit;
    init.x = 5;
    init.y = 4;
    scrLimit.x = 80;
    scrLimit.y = 40;
    Nibbles nib1(init, scrLimit);
    nib1.draw();
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
