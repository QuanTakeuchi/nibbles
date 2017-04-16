#include <ncurses.h>

#include <iostream>
#include <string>
#include "init.hpp"
#include "sprite.hpp"


int main() {
  initCurses();
  try {
    std::string ballFile = "Sprites/ball_1x1.sprt";
    std::string borderFile = "Sprite/border_30x80.sprt";
    Sprite ball(ballFile, 1, 1);
    ball.putAt(1,1);

    Coor init, scrLimit;
    init.x = 5;
    init.y = 4;
    scrLimit.x = 80;
    scrLimit.y = 40;
    Nibbles nib1(init, scrLimit);
    nib1.draw();


    Level lvl1(30, 80, 0, 0);

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
