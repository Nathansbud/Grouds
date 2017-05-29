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
//  HUMAN = 9,
  INVALID
};



class Tile
{
  public:
	Tile(); //Default tile
	Tile(TileType type, int id);
	Tile(const Tile &tile);
	~Tile();
	

	
	TileType GetType() {return _type;}
	std::string GetTypeS() {return _typeS.at(_type);}
  
	
	int GetID() {return _id;}
	
	void Update(int mouseX, int mouseY);
	virtual void Draw();
	
	void SetType(TileType type);
	void SetID(int id) {_id = id;}
	void SetPos(float posX, float posY) {_pos = ofVec2f(posX, posY);}
	void SetSize(float posX, float posY) {_size = ofVec2f(posX, posY);}
	

	
	ofVec2f GetPos() {return _pos;}
	ofVec2f GetSize() {return _size;}
	bool isOccupied();
	bool isMousedOver(int mouseX, int mouseY);
	bool _isSelected;
	
	Tile& operator=(const Tile& obj);
	
	virtual void InitializeData();
	virtual void UpdateData();
//	virtual void AddItem();
	
	void AddData(std::string dat) {_data.push_back(dat);}
	void SetData(int index, std::string dat);
	std::string GetData(int index);
	int GetDataSize() {return _data.size();}

	
	
  private:
	int _id;
	ofVec2f _size;
	ofVec2f _pos;
	TileType _type;
	friend class HUD;
	std::vector<string> _data;
	std::map<TileType, string> _typeS = {{TileType::GROUND, "Ground"},
												{TileType::TREE, "Tree"},
												{TileType::SAND, "Sand"},
												{TileType::ROCK, "Rock"},
												{TileType::WATER, "Water"},
												{TileType::STRUCTURE, "Structure"},
//												{TileType::HUMAN, "Human"},
												{TileType::INVALID, "Invalid"}};
  
  
	

	
};

#endif /* Tile_hpp */
