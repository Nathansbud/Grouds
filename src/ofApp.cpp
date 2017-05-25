#include "ofApp.h"

void ofApp::setup()
{
  ofBackground(255);
  wMap = new WorldMap(MapType::DESERT, 8);
  hud = new HUD(wMap);
  wMap->at(3)->SetType(TileType::WATER);
  wMap->at(8)->SetType(TileType::ROCK);
}

void ofApp::update()
{
  wMap->Update(mouseX, mouseY);
  hud->Update();
}

void ofApp::draw()
{
  wMap->Draw();
  hud->Draw();
}

void ofApp::keyPressed(int key)
{
  tile = new Tile(TileType::WATER, 8);
  tile2 = new Tile(TileType::GROUND, 2);
  
//  *wMap->at(2) = *tile;

  cout << wMap->at(2)->GetTypeS() << tile->GetID() << endl;
}

void ofApp::mousePressed(int x, int y, int mouse)
{
   wMap->SetSelected(wMap->GetMoused());
   cout << wMap->at(wMap->GetSelected()->GetID())->GetID() << endl;
}
