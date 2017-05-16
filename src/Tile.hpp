//
//  Tile.hpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/16/17.
//
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>
#include "ofMain.h"

class Tile
{
  public:
	Tile();
	Tile(int type, int id);
	~Tile();
	int GetType() {return _type;}
	int GetID() {return _id;}
	
	void Draw();
	
	void SetPos(float posX, float posY);
	
	ofVec2f GetSeedPos() {return _seedPos;}
	ofVec2f GetSize() {return _size;}
  
  private:
	int _type;
	int _id;
	ofVec2f _seedPos;
	ofVec2f _size;
	ofVec2f _pos;

};

#endif /* Tile_hpp */
