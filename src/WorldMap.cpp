//
//  WorldMap.cpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/15/17.
//
//

#include "WorldMap.hpp"
#include <string>

WorldMap::WorldMap()
{
  std::cout << "kill me" << std::endl;
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
	  tileMap[i][j]->Draw();
	}
  }
}

void WorldMap::Update()
{

}

void WorldMap::LoadMap(MapType mapType)
{
  std::string currentStage;
  
  switch(mapType)
  {
	case MapType::FOREST:
	  gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/forest.txt");
	  break;
	case MapType::DESERT:
	  gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/desert.txt");
	  break;
	case MapType::OCEAN:
	  gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/ocean.txt");
	  break;
	case MapType::INVALID:
	  gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/template.txt");
  }
  
  int id = 0;
  
  if (!gameMap) std::cout << "Map failed to initialize" << std::endl;
  else std::cout << "Everything went according to plan, boss!" << std::endl;
  
  int i = -1;
  
  while(std::getline(gameMap, line))
  {
	i++;
	for(int j = 0; j < ROW_HEIGHT; j++)
	{
	  
//	  tiles[i][j] = line[j];
//	  std::cout << tiles[i][j] << std::endl;
	  
	  switch(line[j])
	  {
		case 48:
		  _tileType = TileType::GROUND;
		  break;
		case 49:
		  _tileType = TileType::TREE;
		  break;
		case 50:
		  _tileType = TileType::SAND;
		  break;
		case 51:
		  _tileType = TileType::WATER;
		  break;
		case 58:
		  _tileType = TileType::PLAYER;
		  break;
		default:
		  _tileType = TileType::INVALID;
		  break;
	  }
	  
	  tileMap[i][j] = new Tile(_tileType, id); //(TileType)tiles[i][j];
	  tileMap[i][j]->SetPos(tileMap[i][j]->GetSeedPos().x + (tileMap[i][j]->GetSize().x * j), tileMap[i][j]->GetSeedPos().y + (tileMap[i][j]->GetSize().y * i));
	  id++;
	}
	
	if(!gameMap) break;
  }
  gameMap.close();
}

void WorldMap::Parse()
{
  
}

MapType WorldMap::CurrentLevel()
{
  return _mapType;
}
