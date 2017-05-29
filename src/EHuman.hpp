
#ifndef EHuman_hpp
#define EHuman_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "Entity.hpp"

enum class Items
{
  OAK_WOOD,
  PINE_WOOD,
  DFIR_WOOD,
  CACTUS_WOOD,
  STONE,
  COAL,
  IRON,
  SILVER,
  GOLD,
  DIAMOND,
  EMERALD,
  INVALID
};


class EHuman : public Entity
{
  public:
	EHuman(){}
	EHuman(EntityType e, int id);
	~EHuman();
	
	virtual void Draw();
//	virtual void Update();
	
	virtual void InitializeData();
	virtual void UpdateData();
	
	void AddItem(Items item, int quantity);
  
	int GetItem(int index);
	std::string GetItemS(int index);
	bool containsItem(Items item);
	
	int _quantity[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
  private:
	std::vector<Items> _inventory;
	const std::map<Items, std::string> ITEM_LIST = {{Items::OAK_WOOD, "Oak Wood"},
													 {Items::PINE_WOOD, "Pine Wood"},
													 {Items::DFIR_WOOD, "Douglas Fir Wood"},
													 {Items::CACTUS_WOOD, "Cactus"},
													 {Items::COAL, "Coal"},
													 {Items::STONE, "Stone"},
													 {Items::IRON, "Iron"},
													 {Items::SILVER, "Silver"},
													 {Items::GOLD, "Gold"},
													 {Items::DIAMOND, "Diamond"},
													 {Items::EMERALD, "Emerald"},
													 {Items::INVALID, "Invalid"}};
  
	std::map<Items, int> _contains = {{Items::OAK_WOOD, _quantity[0]},
									   {Items::PINE_WOOD, _quantity[1]},
									   {Items::DFIR_WOOD, _quantity[2]},
									   {Items::CACTUS_WOOD, _quantity[3]},
									   {Items::COAL, _quantity[4]},
									   {Items::STONE, _quantity[5]},
									   {Items::IRON, _quantity[6]},
									   {Items::SILVER, _quantity[7]},
									   {Items::GOLD, _quantity[8]},
									   {Items::DIAMOND, _quantity[9]},
									   {Items::EMERALD, _quantity[10]},
									   {Items::INVALID, _quantity[11]}};
};

#endif /* EHuman_hpp */
