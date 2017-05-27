//
//  TRock.cpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/27/17.
//
//

#include "TRock.hpp"

TRock::TRock(TileType type, int id)
{
  SetType(type);
  SetID(id);
  SetData();
}

TRock::~TRock()
{
  
}

void TRock::SetData()
{
  data.push_back(to_string(GetID()));
  data.push_back(GetTypeS());
  data.push_back(GetRockS());
}

void TRock::SetMineral()
{
  int x = (int)ofRandom(100);
  _yields = (int)ofRandom(0, 5);
  
  if(x >= 45)
  {
	_rock = RockType::STONE;
  } else if(x >= 20 && x < 45)
  {
	_rock = RockType::COAL;
  } else if(x < 20 && x >= 10)
  {
	_rock = RockType::IRON;
  } else if(x < 10 && x >= 5)
  {
	_rock = RockType::SILVER;
  } else if(x < 5 && x > 1)
  {
	_rock = RockType::GOLD;
  } else if(x == 1)
  {
	_rock = RockType::DIAMOND;
  }
}
