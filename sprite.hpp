#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include <vector>
#include <fstream>

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


#endif
