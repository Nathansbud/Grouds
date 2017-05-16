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
  
  LoadMap(level);
}

WorldMap::~WorldMap()
{

}

void WorldMap::Draw()
{
 for(int i = 0; i < 8; i++)
  {
	for(int j = 0; j < 8; j++)
	{
	  tileMap[i][j].Draw();
	  tileMap[i][j].SetPos(tileMap[i][j].GetSeedPos().x + (tileMap[i][j].GetSize().x * j), tileMap[i][j].GetSeedPos().y + (tileMap[i][j].GetSize().y * i));
	}
  }
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
	  static int id = 0;
	  while(getline(map, line)) map >> tiles[i][j];
	  tileMap[i][j] = Tile(tiles[i][j], id);
	  id++;
	}
  }
  
  std::cout << tiles << std::endl;
  
  map.close();
}

void WorldMap::Parse()
{
  
}

int WorldMap::CurrentLevel()
{
  return _level;
}
