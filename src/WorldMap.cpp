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

WorldMap::WorldMap(MapType mapType, int size)
{
  rowW = ROW_WIDTH;
  rowH = ROW_HEIGHT;
  _mapSize = size;
  LoadMap(mapType, size);
}

WorldMap::~WorldMap()
{

}

void WorldMap::Draw()
{
  for(int i = 0; i < rowW; i++)
  {
	for(int j = 0; j < rowH; j++)
	{
	  tileMap[i][j]->Draw();
	}
  }
}

void WorldMap::Update()
{
  
}

//void SpawnEntity(TileType t, int num)
//{
//  for(int i = 0; i < num; i++)
//  {
//	int tile = (int)ofRandom(0, 64);
//	at(tile)->SetType(TileType::HUMAN);
//  }
//}

void WorldMap::LoadMap(MapType mapType, int size)
{
  std::string currentStage;
  
  switch(mapType)
  {
	case MapType::FOREST:
	  {
		if(size <= 8) gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/8x8 Maps/forest.txt");
		else if(size > 8 && size <= 16) gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/16x16 Maps/forest.txt");
	  }
	  break;
	case MapType::DESERT:
	  {
		if(size <= 8) gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/8x8 Maps/desert.txt");
		else if(size > 8 && size <= 16) gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/16x16 Maps/desert.txt");
	  }
	  break;
	case MapType::OCEAN:
	  {
		if(size <= 8) gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/8x8 Maps/ocean.txt");
		else if(size > 8 && size <= 16) gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/16x16 Maps/ocean.txt");
	  }
	  break;
	case MapType::INVALID:
	  gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/temp8.txt");
	  break;
  }
  
  int id = 0;
  
  if (!gameMap) std::cout << "Map failed to initialize" << std::endl;
  else std::cout << "Everything went according to plan, boss!" << std::endl;
  
  int iter = -1;
  
  while(std::getline(gameMap, line))
  {
	iter++;
	for(int j = 0; j < rowH; j++)
	{
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
		  _tileType = TileType::HUMAN;
		  break;
		default:
		  _tileType = TileType::INVALID;
		  break;
	  }
	  
	  tileMap[iter][j] = new Tile(_tileType, id);
	  idMap.emplace(id, tileMap[iter][j]);
	  tileMap[iter][j]->SetPos(tileMap[iter][j]->GetSeedPos().x + (tileMap[iter][j]->GetSize().x * j), tileMap[iter][j]->GetSeedPos().y + (tileMap[iter][j]->GetSize().y * iter));
	  id++;
	  
	  
	}
	
	if(!gameMap) break;
  }
  
  gameMap.close();
}

void WorldMap::SpawnEntity(TileType t, int index)
{
  at(index)->SetType(t);
}

void WorldMap::SpawnEntity(int num, TileType t) //Appears to work. Double check later.
{
  vector<int> indexes;
  int tileIndex = (int)ofRandom(0, 64);
  
  for(int i = 0; i < num; i++)
  {
	while(at(tileIndex)->isOccupied())
	{
	  tileIndex = (int)ofRandom(0, 64);
	  
	  for(int x : indexes)
	  {
		if(x == tileIndex)
		{
		  tileIndex = (int)ofRandom(0, 64);
		}
	  }
	}
	
	at(tileIndex)->SetType(t);
	indexes.push_back(tileIndex);
  }
}


void WorldMap::Parse()
{
  
}

MapType WorldMap::CurrentLevel()
{
  return _mapType;
}
