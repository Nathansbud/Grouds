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
	WorldMap(MapType mapType);
	~WorldMap();
	void Draw();
	void Update();
	MapType CurrentLevel();

  private:
	void LoadMap(MapType level);
	std::ifstream gameMap;
	std::string line;
	static const int ROW_WIDTH = 8;
	static const int ROW_HEIGHT = 8;
//	int tiles[ROW_WIDTH][ROW_HEIGHT];
	Tile* tileMap[ROW_WIDTH][ROW_HEIGHT];
	void Parse();
	void SetupTileMap();
	MapType _mapType;
	TileType _tileType;
};



#endif /* WorldMap_hpp */
