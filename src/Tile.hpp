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
#include <stdexcept>
#include <map>
#include "ofMain.h"

enum class TileType
{
  GROUND = 0, //Ground Tile
  TREE = 1,
  SAND = 2, //Ground Tile
  WATER = 3,
  HUMAN = 9,
  INVALID
};

class Tile
{
  public:
	Tile(); //Default tile
	Tile(TileType type, int id);
	~Tile();
	TileType GetType() {return _type;}
	std::string GetTypeS() {return _typeS;}
	
	int GetID() {return _id;}
	
	void Update(int mouseX, int mouseY);
	void Draw();
	
	void SetPos(float posX, float posY);
	void SetType(TileType type);
	
	
	ofVec2f GetSeedPos() {return _seedPos;}
	ofVec2f GetPos() {return _pos;}
	ofVec2f GetSize() {return _size;}
	bool isOccupied();
	bool isMousedOver(int mouseX, int mouseY);
	
  
  private:
	int _id;
	ofVec2f _seedPos;
	ofVec2f _size;
	ofVec2f _pos;
	TileType _type;
	std::string _typeS;
	

	
};

#endif /* Tile_hpp */
