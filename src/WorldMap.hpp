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
#include "ofMain.h"
#include "Tile.hpp"


enum class MapType
{
  FOREST,
  DESERT,
  OCEAN
};

class WorldMap
{
  public:
	WorldMap();
	WorldMap(MapType mapType);
	~WorldMap();
	void Draw();
	void Update();
	int CurrentLevel();

  private:
	void LoadMap(MapType level);
	std::ifstream gameMap;
	std::string line;
	int tiles[8][8];
	Tile tileMap[8][8];
	void Parse();
	void SetupTileMap();
	MapType _mapType;
};



#endif /* WorldMap_hpp */
