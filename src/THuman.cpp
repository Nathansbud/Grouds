//
//  Human.cpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/14/17.
//
//

//#include "THuman.hpp"
//
//THuman::THuman(TileType type, int id)
//{
//  SetType(TileType::HUMAN);
//  SetID(id);
//  InitializeData();
//}
//
//THuman::~THuman()
//{
//
//}
//
//void THuman::InitializeData()
//{
//  AddData("Tile #" + to_string(GetID()));
//  AddData(GetTypeS());
//  AddData("Inventory:");
//  for(auto const& x : ITEM_LIST)
//  {
//	AddData(x.second +  " (" + to_string(_contains.at(x.first)) + ")");
//  }
//}
//
//void THuman::UpdateData()
//{
//  int iter = 0;
//  SetData(0, "Tile #" + to_string(GetID()));
//  SetData(1, GetTypeS());
//  SetData(2, "Inventory:");
//  for(auto const& x : _inventory)
//  {
//    SetData(iter, ITEM_LIST.at(x) + to_string(_contains.at(x)));
////
//	iter++;
//  }
//  
////  AddItem(Items::STONE, 2);
//}
//
//void THuman::AddItem(Items item, int quantity)
//{
//  if(!containsItem(item))
//  {
//	_inventory.push_back(item);
//  }
//  _contains.at(item) += quantity;
//}
//
//std::string THuman::GetItemS(int index)
//{
//  return ITEM_LIST.at(_inventory.at(index));
//}
//
//int THuman::GetItem(int index)
//{
//  return _contains.at(_inventory.at(index));
//}
//
//bool THuman::containsItem(Items item)
//{
//  for(int i = 0; i < _inventory.size(); i++)
//  {
//	if(_inventory.at(i) == item)
//	{
//	  return true;
//	} else return false;
//  }
//}


