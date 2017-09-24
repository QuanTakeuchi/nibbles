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
    Level lvl1(30, 80, 0, 0);

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
    
    WINDOW *control;
    control = newwin(1, 1, scrLimit.y+1, scrLimit.x+1);
    // wrefresh(control);

    
    char ch;
    int err;
    while(ch!='q') {
      ch = wgetch(control);
      switch(ch) {
      case 'w':
	nib1.clearLast();
	nib1.move(UP);
	break;
      case 'a':
	nib1.clearLast();
	nib1.move(LEFT);
	break;
      case 's':
	nib1.clearLast();
	nib1.move(DOWN);
	break;
      case 'd':
	nib1.clearLast();
	nib1.move(RIGHT);
	break;
      default:
	break;
      }
      nib1.draw();
      refresh();
    }
    // getch();
    refresh();
    exitCurses();
  }

  catch(std::runtime_error err) {
    exitCurses();
    std::cout << err.what() << std::endl;
    return 1;
  }
  return 0;
}
