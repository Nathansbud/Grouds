#pragma once

//#include "ofMain.h"
//#include "Human.hpp"
//#include "Mammal.hpp"
//#include "Cat.hpp"
//#include "Animal.hpp"
//#include "BaseAI.hpp"
//#include "Bacteria.hpp"
#include "WorldMap.hpp"
class ofApp : public ofBaseApp
{
	public:
		void setup();
		void update();
		void draw();
  
		WorldMap* wMap;
  private:
};

