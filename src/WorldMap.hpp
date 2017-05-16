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

class WorldMap
{
  public:
	WorldMap(int level);
	~WorldMap();
	void Draw();
	void Update();
	int CurrentLevel();
	enum Level {Forest, Desert, Ocean, END};

  private:
	void LoadMap(int level);
	std::ifstream map;
	std::string line;
	int tiles[8][8];
	Tile tileMap[8][8];

	Level _level;
	enum Type {Default = 0, Tree = 1, Water = 2, Player = 9};
	Type _type;
	void Parse();
	void SetupTileMap();
};

#endif /* WorldMap_hpp */
