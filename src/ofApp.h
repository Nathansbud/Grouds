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
  
		WorldMap* wMap;
		HUD* hud;
  private:
};

