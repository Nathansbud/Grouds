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
  hud->Update();
}

void ofApp::draw()
{
  wMap->Draw();
  hud->Draw();
}

void ofApp::keyPressed(int key)
{
  
}

void ofApp::mousePressed(int x, int y, int mouse)
{
   wMap->SetSelected(wMap->GetMoused());
}
