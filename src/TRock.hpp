//
//  TRock.hpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/27/17.
//
//

#ifndef TRock_hpp
#define TRock_hpp

#include <stdio.h>
#include "Tile.hpp"

enum class RockType
{
  STONE = 0,
  COAL = 1, //Ground Tile
  IRON = 2,
  SILVER = 3,
  GOLD = 4, //Ground Tile
  DIAMOND = 5,
  EMERALD = 6,
  INVALID
};

class TRock : public Tile
{
  public:
	TRock(TileType type, int id);
	~TRock();
	
	virtual void InitializeData();
	virtual void UpdateData();
  
	RockType GetRock() {return _rock;}
	std::string GetRockS() {return _rockS.at(_rock);}
	
	void SetMineral();
		
  private:
	RockType _rock;
	int _yields;
	
	const std::map<RockType, std::string> _rockS = {{RockType::STONE, "Stone"},
													{RockType::COAL, "Coal"},
													{RockType::IRON, "Iron"},
													{RockType::SILVER, "Silver"},
													{RockType::GOLD, "Gold"},
													{RockType::DIAMOND, "Diamond"},
													{RockType::EMERALD, "Emerald"},
													{RockType::INVALID, "Invalid"}};
	
};

#endif /* TRock_hpp */
