//
//  Human.cpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/14/17.
//
//

#include "THuman.hpp"

THuman::THuman(TileType type, int id)
{
  SetType(TileType::HUMAN);
  SetID(id);
  SetData();
}

THuman::~THuman()
{

}

void THuman::SetData()
{
  data.push_back(to_string(GetID()));
  data.push_back(GetTypeS());
}
