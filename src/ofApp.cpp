#include "ofApp.h"

void ofApp::setup()
{
  wMap = new WorldMap(MapType::DESERT);
}

void ofApp::update()
{

}

void ofApp::draw()
{
  wMap->Draw();
}
