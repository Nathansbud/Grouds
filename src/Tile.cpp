//
//  Tile.cpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/16/17.
//
//

#include "Tile.hpp"

Tile::Tile() //Needs a default constructor I believe
{

}

Tile::Tile(TileType type, int id)
{
  _seedPos = ofVec2f(ofGetWidth()/14.4, ofGetHeight()/9);
  SetPos(_seedPos.x, _seedPos.y);
  SetType(type);
  _size = ofVec2f(ofGetWidth()*0.0555555555, ofGetHeight()*0.0888888888);
  id = _id; //0 = Normal, 1 = Tree, 2 = Water, 9 = Human???
}

Tile::~Tile()
{

}

void Tile::Draw()
{
  ofFill();
  switch(GetID())
  {
	case 0:
	  ofSetColor(76, 70, 50);
	  break;
	case 1:
	  ofSetColor(0, 100, 0);
	  break;
	case 2:
	  ofSetColor(235, 244, 250);
	  break;
	default:
	  ofSetColor(0);
	  break;
	
  }
  ofDrawRectangle(_pos, _size.x, _size.y);
  ofNoFill();
}

void Tile::SetPos(float posX, float posY)
{
  _pos = ofVec2f(posX, posY);
}

void Tile::SetType(TileType type)
{
  _type = type;
}



