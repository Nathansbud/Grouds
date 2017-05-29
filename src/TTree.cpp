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
  InitializeData();
}

TTree::~TTree()
{

}

void TTree::SetSpecies(TreeType species)
{
  _species = species;
  SetHeight();
}

void TTree::InitializeData()
{
  AddData("Tile #" + to_string(GetID()));
  AddData(GetTypeS());
  AddData("Species: " + GetSpeciesS());
}

void TTree::UpdateData()
{
  SetData(0, "Tile #" + to_string(GetID()));
  SetData(1, GetTypeS());
  SetData(2, "Species: " + GetSpeciesS());
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
