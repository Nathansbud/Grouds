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
  GetData(_map->GetMoused());
  cout << _map->at(14)->GetTypeS() << endl;
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
	ofDrawBitmapString("Moused Over:", _rightPos.x, _mElement(0));
	ofDrawBitmapString("Tile #" + _moused->GetData(0), _rightPos.x, _mElement(1));
	ofDrawBitmapString(_moused->GetData(1), _rightPos.x, _mElement(2));
//	ofDrawBitmapString(
  }
  
  if(_map->_tileSelected)
  {
	ofDrawBitmapString("Selected:", _rightPos.x, _sElement(0));
	ofDrawBitmapString("Tile #" + _selected->GetData(0), _rightPos.x, _sElement(1));
	ofDrawBitmapString("Tile Type: " + _selected->GetData(1), _rightPos.x, _sElement(2));
	if(_selected->GetType() == TileType::SAND)
	{
	  ofDrawBitmapString("wat" + _selected->GetData(2), _rightPos.x, _sElement(3));
	}
  }
  
  
  ofDrawBitmapString("Time Elapsed: " + to_string((int)ofGetElapsedTimef()), _leftPos.x, _leftPos.y); //Time in Seconds
  
  std::string _dim = to_string((int)sqrt(_size)) + 'x' + to_string((int)sqrt(_size)); //Dimensions, grabs root(map size)xroot(map size). Set up in the event that more/complex map types are made in the future.
  
  ofDrawBitmapString("Map Size: " + to_string(_map->GetMapSize()) + ' ' + '(' + _dim + ')', _leftPos.x, _leftPos.y + ofGetHeight()/30);
}

void HUD::GetData(Tile* tile)
{
  _name = _map->GetMapName();
  
  if(_map->_tileMoused)
  {
	_moused = _map->GetMoused();
  }
  
  if(_map->_tileSelected)
  {
	_selected = _map->GetSelected();
  }
}

