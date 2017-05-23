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
  _seedPos = ofVec2f(ofGetWidth()/14.4*4, ofGetHeight()/9);
  SetPos(_seedPos.x, _seedPos.y); //Maybe find a better way of doing this?
  SetType(type);
  _size = ofVec2f(ofGetWidth()*0.0555555555, ofGetWidth()*0.0555555555); //Change this to be variable later @ 8 vs 16 size maps
   _id = id;
}

Tile::~Tile()
{

}

void Tile::Update(int mouseX, int mouseY)
{
  isMousedOver(mouseX, mouseY);
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
	  ofSetColor(0, 0, 225); //Dark Blue
	  break;
	case TileType::HUMAN:
	  ofSetColor(0);
	  break;
	case TileType::INVALID:
	  throw std::invalid_argument("Received Invalid Tile");
	  break;
	
  }
  ofDrawRectangle(_pos, _size.x, _size.y);
  ofNoFill();
}

bool Tile::isOccupied()
{
  switch(_type)
  {
	case TileType::GROUND:
	case TileType::SAND:
	  return false;
	  break;
	case TileType::TREE:
	case TileType::HUMAN:
	case TileType::WATER:
	  return true;
	  break;
	case TileType::INVALID:
	  throw std::invalid_argument("Received Invalid Tile");
	  break;
  }
}

bool Tile::isMousedOver(int mouseX, int mouseY)
{
  if(mouseX < _pos.x + _size.x && mouseX > _pos.x && mouseY > _pos.y && mouseY < _pos.y + _size.y)
  {
	return true;
  } else return false;
}

void Tile::SetPos(float posX, float posY)
{
  _pos = ofVec2f(posX, posY);
}

void Tile::SetType(TileType type)
{
  _type = type;
  switch(type)
  {
	case TileType::GROUND:
	  _typeS = "Ground";
	  break;
	case TileType::WATER:
	  _typeS = "Water";
	  break;
	case TileType::SAND:
	  _typeS = "Sand";
	  break;
	case TileType::HUMAN:
	  _typeS = "Human";
	  break;
	case TileType::TREE:
	  _typeS = "Tree";
	  break;
	case TileType::INVALID:
	  _typeS = "Invalid";
	  break;
  }
}



