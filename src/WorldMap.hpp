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

class WorldMap
{
  public:
	WorldMap(int level);
	~WorldMap();
	void Draw();
	void Update();
	int CurrentLevel();
  
  private:
	void LoadMap(int level);
	std::ifstream map;
	std::string line;
	int tiles[8][8];
	enum Level {Forest, Desert, Ocean, END};
	Level _level;
	enum Type {Default = 0, Tree = 1, Water = 2, Player = 9};
	Type _type;
	void Parse();
};

#endif /* WorldMap_hpp */
