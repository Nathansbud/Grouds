//
//  EHuman.cpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/29/17.
//
//

#include "EHuman.hpp"

EHuman::EHuman(EntityType e, int id)
{
  SetEntity(e);
  SetID(id);
  InitializeData();
//  cout << GetData(1) << endl;
}


EHuman::~EHuman()
{

}

//void EHuman::Draw()
//{
//  
//}

void EHuman::InitializeData()
{
  AddData("Tile #" + std::to_string(GetID()));
  AddData(GetEntityS());
  AddData("Inventory:");
  for(auto const& x : ITEM_LIST)
  {
	AddData(x.second +  " (" + std::to_string(_contains.at(x.first)) + ")");
  }
}

void EHuman::UpdateData()
{
  int iter = 0;
  SetData(0, "Tile #" + std::to_string(GetID()));
  SetData(1, GetEntityS());
  SetData(2, "Inventory:");
  for(auto const& x : _inventory)
  {
    SetData(iter, ITEM_LIST.at(x) + std::to_string(_contains.at(x)));
	iter++;
  }
}

void EHuman::AddItem(Items item, int quantity)
{
  if(!containsItem(item))
  {
	_inventory.push_back(item);
  }
  _contains.at(item) += quantity;
}

std::string EHuman::GetItemS(int index)
{
  return ITEM_LIST.at(_inventory.at(index));
}

int EHuman::GetItem(int index)
{
  return _contains.at(_inventory.at(index));
}

bool EHuman::containsItem(Items item)
{
  for(int i = 0; i < _inventory.size(); i++)
  {
	if(_inventory.at(i) == item)
	{
	  return true;
	} else return false;
  }
}


