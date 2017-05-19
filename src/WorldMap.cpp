//
//  WorldMap.cpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/15/17.
//
//

#include "WorldMap.hpp"

WorldMap::WorldMap()
{

}

WorldMap::WorldMap(MapType mapType)
{
  LoadMap(mapType);
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
	}
  }
}

void WorldMap::Update()
{

}

void WorldMap::LoadMap(MapType mapType)
{
  std::string currentStage;
  std::string stage[] = {"forest", "desert", "ocean"};
  
  switch(mapType)
  {
	case MapType::FOREST:
	  currentStage = stage[MapType::FOREST];
	  break;
	case MapType::DESERT:
	  currentStage = stage[MapType::DESERT];
	  break;
	case MapType::OCEAN:
	  currentStage = stage[MapType::OCEAN];
	  break;
  }
  
  gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/" + currentStage + ".txt");
  if (!gameMap) std::cout << "Map failed to initialize" << std::endl;
  
  for(int i = 0; i < 8; i++)
  {
	for(int j = 0; j < 8; j++)
	{
	  static int id = 0;
	  while(getline(gameMap, line)) gameMap >> tiles[i][j];
	  tileMap[i][j] = Tile((Tile::TileType)tiles[i][j], id);
	  tileMap[i][j].SetPos(tileMap[i][j].GetSeedPos().x + (tileMap[i][j].GetSize().x * j), tileMap[i][j].GetSeedPos().y + (tileMap[i][j].GetSize().y * i));

	  id++;
	}
  }
  
  std::cout << tiles << std::endl;
  
  gameMap.close();
}

void WorldMap::Parse()
{
  
}

int WorldMap::CurrentLevel()
{
  return _mapType;
}
