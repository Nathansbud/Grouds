#include "ofApp.h"

void ofApp::setup()
{
  ofBackground(255);
  wMap = new WorldMap(MapType::DESERT, 8);
  hud = new HUD(wMap);
}

void ofApp::update()
{
  wMap->Update(mouseX, mouseY);
  hud->Update(wMap);
}

void ofApp::draw()
{
  wMap->Draw();
  hud->Draw();
}

void ofApp::keyPressed(int key)
{
  wMap->at(3)->SetType(TileType::WATER);
}

void ofApp::mousePressed(int x, int y, int mouse)
{
   wMap->SetSelected(wMap->GetMoused());
   cout << wMap->GetSelected()->GetData(1) << endl;
}
