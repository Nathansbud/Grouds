//
//  TTree.hpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/27/17.
//
//

#ifndef TTree_hpp
#define TTree_hpp

#include "Tile.hpp"

enum class TreeType
{
  OAK = 0,
  PINE = 1,
  DFIR = 2,
  CACTUS = 3
};

class TTree : public Tile
{
  public:
	TTree(TileType type, int id);
	~TTree();
	virtual void SetData();
	
	TreeType GetSpecies() {return _species;}
	std::string GetSpeciesS() {return _speciesS.at(_species);}
	void SetSpecies(TreeType species);
	void SetSpecies();
	void SetHeight();
	
  private:
	TreeType _species;
	
	float _height;
	int _yields;
	
	const std::map<TreeType, std::string> _speciesS = {{TreeType::OAK, "Oak"},
														{TreeType::PINE, "Pine"},
														{TreeType::DFIR, "Douglas Fir"},
														{TreeType::CACTUS, "Cactus"}};
};

#endif /* TTree_hpp */
