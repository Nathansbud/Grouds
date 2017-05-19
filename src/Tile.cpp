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
  switch(GetType())
  {
	case TileType::GROUND:
	  ofSetColor(76, 70, 50);
	  break;
	case TileType::TREE:
	  ofSetColor(0, 100, 0);
	  break;
	case TileType::SAND:
	  ofSetColor(237, 201, 175);
	  break;
	case TileType::WATER:
	  ofSetColor(0, 255, 255);
	  break;
	case TileType::PLAYER:
	  ofSetColor(0);
	  break;
	case TileType::INVALID:
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



