//
//  WorldMap.cpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/15/17.
//
//

#include "WorldMap.hpp"

WorldMap::WorldMap(int level)
{
  _level = (Level)level;
  
  LoadMap(_level);
}

WorldMap::~WorldMap()
{

}

void WorldMap::Draw()
{

}

void WorldMap::Update()
{

}

void WorldMap::LoadMap(int level)
{
  std::string stage;
  
  switch(level)
  {
	case 0:
	  stage = "forest";
	  break;
	case 1:
	  stage = "desert";
	  break;
	case 2:
	  stage = "ocean";
	  break;
  }
  
  map.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/" + stage + ".txt");
  if (!map) std::cout << "Map failed to initialize" << std::endl;
  
  for(int i = 0; i < 8; i++)
  {
	for(int j = 0; j < 8; j++)
	{
	  map >> tiles[i][j];
	}
  }
  
  std::cout << tiles << std::endl;
  
  map.close();
}

void WorldMap::Parse()
{
  /*
  
  0 = Ground
  1 = Tree
  2 = Water
  3 ~ 8 = ???
  9 = Player
  
  */
}

int WorldMap::CurrentLevel()
{
  return _level;
}
