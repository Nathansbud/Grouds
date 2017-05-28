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
  InitializeData();
}

THuman::~THuman()
{

}

void THuman::InitializeData()
{
  AddData("Tile #" + to_string(GetID()));
  AddData(GetTypeS());
}

void THuman::UpdateData()
{
  SetData(0, "Tile #" + to_string(GetID()));
  SetData(1, GetTypeS());
}
