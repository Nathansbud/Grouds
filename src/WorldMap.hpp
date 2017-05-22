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
#include "ofMain.h"
#include "Tile.hpp"


enum class MapType
{
  FOREST,
  DESERT,
  OCEAN,
  INVALID
};

class WorldMap
{
  public:
	WorldMap();
	WorldMap(MapType mapType, int size);
	~WorldMap();
	void Draw();
	void Update();
	
	void SpawnEntity(int num, TileType type);
	void SpawnEntity(TileType type, int index);
	
	MapType CurrentLevel();
	Tile* at(int tileID) {return idMap[tileID];}
	
	int GetMapSize() {return _mapSize;}

  private:
	void LoadMap(MapType level, int size);
	std::ifstream gameMap;
	std::string line;
	static const int ROW_WIDTH = 8;
	static const int ROW_HEIGHT = 8;
	
	int rowW, rowH;
		
	Tile* tileMap[ROW_WIDTH][ROW_HEIGHT];
	void Parse();
	void SetupTileMap();
	int _mapSize;
	MapType _mapType;
	TileType _tileType;
	std::map<int, Tile*> idMap;
};



#endif /* WorldMap_hpp */
