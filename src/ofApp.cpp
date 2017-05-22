#include "ofApp.h"

void ofApp::setup()
{
  wMap = new WorldMap(MapType::FOREST, 8);
  wMap->SpawnEntity(3, TileType::HUMAN);
}

void ofApp::update()
{

}

void ofApp::draw()
{
  wMap->Draw();
}
