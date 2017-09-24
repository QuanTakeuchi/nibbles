#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include <vector>
#include <fstream>
#include <assert.h>


enum DIRECIONS{ UP, DOWN, LEFT, RIGHT};

struct Coor {
  int x;
  int y;
};

class Sprite {
  int sprtHeight;
  int sprtWidth;
  std::vector<char> spriteData;
public:
  Sprite(std::string spriteFile, int x, int y);
  int putAt(int xloc, int yloc);
};

Sprite::Sprite(std::string spriteFile, int height, int width) {
  sprtHeight = height;
  sprtWidth = width;

  std::ifstream iSpStream(spriteFile.c_str());

  if(!iSpStream) {
    throw std::runtime_error("Unable to open file");
  }

  char ch=iSpStream.get();
  while(!iSpStream.eof()) {
    spriteData.push_back(ch);
    ch = iSpStream.get();
  }

  if(spriteData.size()!=height*width) {
    throw std::runtime_error("Sprite File Dimenstions dont match");
  }

}

int Sprite::putAt(int xloc, int yloc) {
  for(int i=0; i<sprtHeight; i++) {
    for(int j=0; j<sprtWidth; j++) {
      mvaddch(yloc+i, xloc+j, spriteData[i*sprtWidth+j]);
    }
  }
  refresh();
  return 0;
}

class Nibbles {
  int size;
  std::vector<Coor> body;
  char head;
  char tail;
  Coor scrLimit;
  int movDirection;
  Coor food;
public:
  Nibbles(Coor init, Coor limits) {
    head = 'o';
    tail = 'o';
    size = 3;
    body.resize(size);

    body[0] = init;
    scrLimit = limits;

    for(int i=1; i<size; i++) {
      assert(body[i-1].x > 1);
      body[i].x = body[i-1].x-1;
      body[i].y = body[i-1].y;
      assert(body[i].x < scrLimit.x && body[i].y<scrLimit.y &&
	     body[i].y > 1);
    }
  }

  int draw() {
    mvaddch(body[0].y, body[0].x, head);
    for(int i=1; i<size; i++) {
      mvaddch(body[i].y, body[i].x, tail);
    }
    return 0;
  }

  int clearLast() {
    mvaddch(body[size-1].y, body[size-1].x, ' ');
    return 0;
  }

  int move(int movDirection) {
    for(int i=size-1; i>0; i--) {
      body[i].x = body[i-1].x;
      body[i].y = body[i-1].y;
    }
    switch(movDirection) {
    case DOWN: 
      body[0].y = body[0].y+1;
      break;
    case UP:
      body[0].y = body[0].y-1;
      break;
    case RIGHT:
      body[0].x = body[0].x+1;
      break;
    case LEFT:
      body[0].x = body[0].x-1;
      break;
    default:
      return 101;
    }
    return 0;
  }
};

class Level {
  WINDOW *lvl_win;
public:
  Level(int height, int width, int starty, int startx) {
    lvl_win = newwin(height, width, starty, startx);
    box(lvl_win, 0, 0);
    wrefresh(lvl_win);
  }

  // ~Level() {
  //   wborder(lvl_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  //   wrefresh(lvl_win);
  //   delwin(lvl_win);
  // }

};



#endif
