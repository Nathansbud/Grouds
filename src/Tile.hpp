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
#include <string>
#include <map>
#include "ofMain.h"

enum class TileType
{
  GROUND = 0, //Ground Tile
  TREE = 1,
  SAND = 2, //Ground Tile
  WATER = 3,
  ROCK = 4,
  STRUCTURE = 5,
  HUMAN = 9,
  INVALID
};



class Tile
{
  public:
	Tile(); //Default tile
	Tile(TileType type, int id);
	Tile(const Tile &tile);
	~Tile();
	
	virtual void SetData();
	std::string GetData(int index);
	
	TileType GetType() {return _type;}
	std::string GetTypeS() {return _typeS.at(_type);}
  
	
	int GetID() {return _id;}
	
	void Update(int mouseX, int mouseY);
	void Draw();
	
	void SetType(TileType type);
	void SetID(int id) {_id = id;}
	void SetPos(float posX, float posY) {_pos = ofVec2f(posX, posY);}
	
	ofVec2f GetSeedPos() {return _seedPos;}
	ofVec2f GetPos() {return _pos;}
	ofVec2f GetSize() {return _size;}
	bool isOccupied();
	bool isMousedOver(int mouseX, int mouseY);
	bool _isSelected;
	
	Tile& operator=(const Tile& obj);
	
	std::vector<string> data;
	
  private:
	int _id;
	ofVec2f _seedPos;
	ofVec2f _size;
	ofVec2f _pos;
	TileType _type;
	friend class HUD;
	const std::map<TileType, string> _typeS = {{TileType::GROUND, "Ground"},
												{TileType::TREE, "Tree"},
												{TileType::SAND, "Sand"},
												{TileType::ROCK, "Rock"},
												{TileType::WATER, "Water"},
												{TileType::STRUCTURE, "Structure"},
												{TileType::HUMAN, "Human"},
												{TileType::INVALID, "Invalid"}};
  
  
	

	
};

#endif /* Tile_hpp */
