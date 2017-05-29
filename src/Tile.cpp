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
  _type = type;
  SetID(id);
  InitializeData();
}

Tile::Tile(const Tile &obj)
{
  _type = obj._type;
}

Tile& Tile::operator=(const Tile& obj)
{
  this->_type = obj._type;
  this->_pos = obj._pos;
}

Tile::~Tile()
{

}

void Tile::InitializeData()
{
  AddData("Tile #" + to_string(GetID()));
  AddData(GetTypeS());
}

void Tile::SetData(int index, std::string dat)
{
  _data.at(index) = dat;
}

void Tile::UpdateData()
{
  SetData(0, "Tile #" + to_string(GetID()));
  SetData(1, GetTypeS());
}

std::string Tile::GetData(int index)
{
  return _data.at(index);
}

void Tile::Update(int mouseX, int mouseY)
{
  UpdateData();
  isMousedOver(mouseX, mouseY);
}

void Tile::Draw()
{
  ofFill();
  switch(GetType())
  {
  	case TileType::GROUND:
	case TileType::INVALID:
	  {
		ofSetColor(76, 70, 50);
		if(GetType() == TileType::INVALID)
		{
		  cout << to_string(GetID()) + " is invalid" << endl;
		}
	  }
	  
	  break;
	case TileType::TREE:
	  ofSetColor(0, 100, 0);
	  break;
	case TileType::SAND:
	  ofSetColor(205, 165, 32);
	  break;
	case TileType::WATER:
	  ofSetColor(0, 0, 225); //Dark Blue
	  break;
	case TileType::ROCK:
	  ofSetColor(50);
	  break;
	case TileType::STRUCTURE:
	  ofSetColor(133, 94, 66);
	  break;
//	case TileType::INVALID:
//	  throw std::invalid_argument("Received Invalid Tile");
//	  break;
	
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
	case TileType::INVALID:
	  throw std::invalid_argument("Received Invalid Tile");
	  break;
	default:
	  return true;
  }
}

bool Tile::isMousedOver(int mouseX, int mouseY)
{
  if(mouseX < _pos.x + _size.x && mouseX > _pos.x && mouseY > _pos.y && mouseY < _pos.y + _size.y)
  {
	return true;
  } else return false;
}

void Tile::SetType(TileType type)
{
  _type = type;
}




