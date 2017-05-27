//
//  TTree.cpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/27/17.
//
//

#include "TTree.hpp"

TTree::TTree(TileType type, int id)
{
  SetType(type);
  SetSpecies();
  SetID(id);
  SetData();
}

TTree::~TTree()
{

}

void TTree::SetSpecies(TreeType species)
{
  _species = species;
  SetHeight();
}

void TTree::SetData()
{
  data.push_back(to_string(GetID()));
  data.push_back(GetTypeS());
  data.push_back(GetSpeciesS());
}

void TTree::SetSpecies()
{
  int r = (int)ofRandom(0, 4);
  switch(r)
  {
	case 0:
	  {
		_species = TreeType::OAK;
		_height = (int)ofRandom(10, 24);
	  }
	  break;
	case 1:
	  {
		_species = TreeType::PINE;
		_height = (int)ofRandom(15, 45);
	  }
	  break;
	case 2:
	  {
		_species = TreeType::DFIR;
		_height = ofRandom(60, 75);
	  }
	  break;
	case 3:
	  {
		_species = TreeType::CACTUS;
		_height = ofRandom(3, 10);
	  }
	  break;
  }
}
