//
//  HUD.cpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/23/17.
//
//

#include "HUD.hpp"

HUD::HUD(WorldMap* map)
{
  _map = map;
  _name = _map->GetMapName();
  _size = _map->GetMapSize();

  _rightPos = ofVec2f(ofGetWidth()/1.25, ofGetHeight()/9);
  _leftPos = ofVec2f(ofGetWidth()/8, ofGetHeight()/9);
}

HUD::~HUD()
{

}

void HUD::Update()
{
  GetData(_map->isMoused());
}

void HUD::Draw()
{
  GetInfo();
}

void HUD::GetInfo()
{
  ofSetColor(0);
  ofDrawBitmapString(_name, ofGetWidth()/2, ofGetHeight()/10); //Has a strange tendency to output what appears to be a random string of characters, will investigate this further...or fails to show entirely? Size works as intended, as do id & _type. Not sure why this one happens.
  if(_map->_tileMoused)
  {
	ofDrawBitmapString("Tile #" + to_string(_id + 1), _rightPos.x, _rightPos.y);
	ofDrawBitmapString(_type, _rightPos.x, _rightPos.y + ofGetHeight()/30);
  }
  
  
  
  ofDrawBitmapString("Time Elapsed: " + to_string((int)ofGetElapsedTimef()), _leftPos.x, _leftPos.y);
  
  std::string _dim = to_string((int)sqrt(_size)) + 'x' + to_string((int)sqrt(_size));
  
  ofDrawBitmapString("Map Size: " + to_string(_map->GetMapSize()) + ' ' + '(' + _dim + ')', _leftPos.x, _leftPos.y + ofGetHeight()/30);
}

void HUD::GetData(Tile* tile)
{
  _name = _map->GetMapName();
  
  if(_map->_tileMoused)
  {
	_id = _map->isMoused()->GetID();
	_type = _map->isMoused()->GetTypeS();
  }
}

