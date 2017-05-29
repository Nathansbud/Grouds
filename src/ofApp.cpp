#include "ofApp.h"

void ofApp::setup()
{
  ofBackground(255);
  wMap = new WorldMap(MapType::DESERT, 8); //Initializes map, using text file—as of now, the "8" is useless, but it will be used later for scaling purposes
  hud = new HUD(wMap); //Creates a hud pointing to the created map
}

void ofApp::update()
{
  wMap->Update(mouseX, mouseY); //Updates moused tile
  hud->Update(wMap); //Updates changes from wMap—might be unnecessary?
}

void ofApp::draw()
{
  wMap->Draw();
  if(hud)
  {
	hud->Draw();
  }
}

void ofApp::keyPressed(int key)
{
  wMap->at(3)->SetType(TileType::WATER);
  wMap->at(12)->SetType(TileType::GROUND);
//  wMap->at(44)->AddItem(Items::OAK_WOOD, 1);
}

void ofApp::mousePressed(int x, int y, int mouse)
{
   wMap->SetSelected(wMap->GetMoused()); //Set selected tile to moused tile. To Do: Change this to be within the boundaries of wMap
}
