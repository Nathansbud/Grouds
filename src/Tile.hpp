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

enum class TileType
{
  GROUND = 0,
  TREE = 1,
  SAND = 2,
  WATER = 3,
  PLAYER = 9,
  INVALID
};

class Tile
{
  public:
	Tile(); //Default tile
	Tile(TileType type, int id);
	~Tile();
	TileType GetType() {return _type;}
	int GetID() {return _id;}
	
	void Draw();
	
	void SetPos(float posX, float posY);
	
	ofVec2f GetSeedPos() {return _seedPos;}
	ofVec2f GetSize() {return _size;}
	
  
  private:
  
	void SetType(TileType type);
	int _id;
	ofVec2f _seedPos;
	ofVec2f _size;
	ofVec2f _pos;
	TileType _type;
	
};

#endif /* Tile_hpp */
