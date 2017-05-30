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
  std::cout << "kill me" << std::endl; //why is this still here?
}

WorldMap::WorldMap(MapType mapType, int size)
{
  rowW = ROW_WIDTH;
  rowH = ROW_HEIGHT;
  _mapSize = size;
  _isInit = true;
  LoadMap(mapType, size); //Load in map of type mapType
}

WorldMap::~WorldMap() //To Do: Make this real
{

}

void WorldMap::Draw()
{
  for(int i = 0; i < 64; i++)
  {
	at(i)->Draw(); //Draw every tile in the map. Could also change this to just use ID?
  }
}

void WorldMap::Update(int mouseX, int mouseY)
{
  CheckMoused(mouseX, mouseY); //Checks moused over tile in update
  for(int i = 0; i < 64; i++)
  {
	at(i)->Update(mouseX, mouseY);
  }
}

void WorldMap::LoadMap(MapType mapType, int size)
{
  _mapType = mapType;
  _seedPos = ofVec2f(ofGetWidth()/14.4*4, ofGetHeight()/9); //Sets "seed" pos here for each tile
  
  switch(mapType) //Open correct map
  {
	case MapType::FOREST:
	  {
		if(size <= 8)
		{
		 gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/8x8 Maps/forest.txt");
		 entMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/8x8 Maps/forestentities.txt");
		}
		
		else if(size > 8 && size <= 16) gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/16x16 Maps/forest.txt"); //as of yet unimplemented
	  }
	  break;
	case MapType::DESERT:
	  {
		if(size <= 8)
		{
		  gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/8x8 Maps/desert.txt");
		  entMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/8x8 Maps/desertentities.txt");
		}
		else if(size > 8 && size <= 16) gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/16x16 Maps/desert.txt");
	  }
	  break;
	case MapType::OCEAN:
	  {
		if(size <= 8)
		{
		  gameMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/8x8 Maps/ocean.txt");
		  entMap.open("/Users/zachamiton/GitHub/Testing Grouds/bin/data/8x8 Maps/oceanentities");
		}
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
  
  while(std::getline(gameMap, line)) //loads each line in a block
  {
	iter++;
	for(int j = 0; j < rowH; j++)
	{
	  switch(line[j]) //Loads in each tile's number based on the letter loaded in from the text file //STRONG NOTE YOU CAN LOAD IN ASCII LETTERS!!!!!!!
	  {
		case 48:
//		  {
			_tileType = TileType::GROUND;
//			tileMap[iter][j] = new Tile(_tileType, id);
//		  }
		  break;
		case 49:
//		  {
			_tileType = TileType::TREE;
//			tileMap[iter][j] = new TTree(_tileType, id);
//		  }
		  break;
		case 50:
//		  {
			_tileType = TileType::SAND;
//			tileMap[iter][j] = new Tile(_tileType, id);
//		  }
		  break;
		case 51:
//		  {
			_tileType = TileType::WATER;
//			tileMap[iter][j] = new Tile(_tileType, id);
//		  }
		  break;
		case 52:
//		  {
			_tileType = TileType::ROCK;
//			tileMap[iter][j] = new TRock(_tileType, id);
//		  }
		  break;
		default:
		  _tileType = TileType::INVALID;
		  break;
	  }
	  
	  switch(_tileType) //Could condense this with switch above?
	  {
//		case TileType::HUMAN:
//		  tileMap[iter][j] = new THuman(_tileType, id);
//		  break;
		case TileType::ROCK:
		  tileMap[iter][j] = new TRock(_tileType, id);
		  break;
		case TileType::TREE:
		  tileMap[iter][j] = new TTree(_tileType, id);
		  break;
		default:
		  tileMap[iter][j] = new Tile(_tileType, id);
		  break;
	  }
	  
	  _idMap.emplace(id, tileMap[iter][j]); //Assign each id to a tile
	  tileMap[iter][j]->SetSize(ofGetWidth()*0.05555555555, ofGetWidth()*0.0555555555); //80x80
	  tileMap[iter][j]->SetPos(_seedPos.x + (tileMap[iter][j]->GetSize().x * j), _seedPos.y + (tileMap[iter][j]->GetSize().y * iter)); //Set position
	  id++;
	  
	  
	}
	
	if(!gameMap) break;
  }
  
  gameMap.close();
  
  iter = -1;
  id = 0;
  
  while(std::getline(entMap, line))
  {
	iter++;
	for(int j = 0; j < rowH; j++)
	{
	  switch(line[j])
	  {
		case 49:
		  {
			_entType = EntityType::HUMAN;
			entityMap[iter][j] = new EHuman(_entType, id);
			entityMap[iter][j]->SetSize(ofGetWidth()*0.055555555, ofGetWidth()*0.055555555);
			entityMap[iter][j]->SetPos(_seedPos.x + (entityMap[iter][j]->GetSize().x * j), _seedPos.y + (tileMap[iter][j]->GetSize().y * iter));
			cout << to_string(entityMap[iter][j]->GetID()) << endl;
			_entidMap.emplace(id, entityMap[iter][j]);

		  }
		  break;
		default:
		  break;
	  }
	  id++;
	}
  }
}

void WorldMap::SpawnEntity(TileType t, int index) 
{
  at(index)->SetType(t);
}


Tile* WorldMap::CheckMoused(int mouseX, int mouseY)
{
  for(int i = 0; i < MAP_SIZE; i++)
  {
	if(at(i)->isMousedOver(mouseX, mouseY))
	{
	  _mousedTile = at(i);
	  _tileMoused = true;
	  return at(i);
	} else _tileMoused = false;
  }
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


void WorldMap::MoveTile(int t1, int t2)
{
  int ids[2] = {at(t1)->GetID(), at(t2)->GetID()};
  
//  at(t1)->SetType(temp[1]);
//  at(t2)->SetType(temp[0]);
}

void WorldMap::SetSelected(Tile* t)
{
  _selectedTile = t;
  _tileSelected = true;
}

void WorldMap::Save()
{

}
