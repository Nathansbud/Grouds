#include "ofApp.h"

void ofApp::setup()
{
  ofBackground(255);
  wMap = new WorldMap(MapType::FOREST, 8);
  hud = new HUD(wMap);
  wMap->at(3)->SetType(TileType::WATER);

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

