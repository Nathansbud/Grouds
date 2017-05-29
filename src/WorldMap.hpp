//
//  WorldMap.hpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/15/17.
//
//

#ifndef WorldMap_hpp
#define WorldMap_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include "ofMain.h"
#include "Tile.hpp"
#include "THuman.hpp"
#include "TRock.hpp"
#include "TTree.hpp"
#include "Entity.hpp"
#include "EHuman.hpp"


enum class MapType
{
  FOREST,
  OCEAN,
  DESERT,
  INVALID
};

class WorldMap
{
  public:
	WorldMap();
	WorldMap(MapType mapType, int size);
	~WorldMap();
	
	void Update(int mouseX, int mouseY);
	void Draw();
	
	void SpawnEntity(int num, TileType type);
	void SpawnEntity(TileType type, int index);
	
	MapType GetMap() {return _mapType;}
	std::string GetMapName() {return _mapName[_mapType];}
	
	Tile* at(int tileID) {return _idMap[tileID];}
	Tile* CheckMoused(int mouseX, int mouseY);
	Tile* GetMoused() {return _mousedTile;}
	Tile* GetSelected() {return _selectedTile;}
	
	void SetSelected(Tile* t);
	void MoveTile(int t1, int t2);
  
	int GetMapSize() {return MAP_SIZE;}
	
	bool _isInit;
	bool _tileMoused;
	bool _tileSelected;
	
	void Save();

  private:
	void LoadMap(MapType level, int size);
	std::ifstream gameMap;
	std::ifstream entMap;
	std::string line;
	static const int ROW_WIDTH = 8;
	static const int ROW_HEIGHT = 8;
	static const int MAP_SIZE = ROW_WIDTH * ROW_HEIGHT;
	
	int rowW, rowH;
	ofVec2f _seedPos;
	
	Tile* tileMap[ROW_WIDTH][ROW_HEIGHT];
	Entity* entityMap[ROW_WIDTH][ROW_HEIGHT];
	
	Tile* _mousedTile;
	Tile* _selectedTile;
	void Parse();
	void SetupTileMap();
	int _mapSize;
	MapType _mapType;
	TileType _tileType;
	EntityType _entType;
	
	std::map<int, Tile*> _idMap;
	std::map<MapType, std::string> _mapName = {{MapType::FOREST, "Forest"},
												{MapType::OCEAN, "Ocean"},
												{MapType::DESERT, "Desert"},
												{MapType::INVALID, "Invalid"}};
};



#endif /* WorldMap_hpp */
