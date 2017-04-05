#ifndef _INIT_HPP_
#define _INIT_HPP_

void initCurses() {
  initscr();
  curs_set(0);
}


void exitCurses() {
  endwin();
}

#endif
