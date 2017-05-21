#include "ofApp.h"

void ofApp::setup()
{
  wMap = new WorldMap(MapType::FOREST, 8);
}

void ofApp::update()
{

}

void ofApp::draw()
{
  wMap->Draw();
}
