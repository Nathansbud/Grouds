#pragma once


#include "ofMain.h"
#include "WorldMap.hpp"
#include "Human.hpp"
#include "HUD.hpp"

class ofApp : public ofBaseApp
{
	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void mousePressed(int x, int y, int mouse);
  
		WorldMap* wMap;
		HUD* hud;
		Tile* tile;
		Tile* tile2;
  private:
};

