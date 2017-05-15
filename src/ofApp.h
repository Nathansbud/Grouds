#pragma once

#include "ofMain.h"
#include "Human.hpp"
#include "Mammal.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
		void Movement(Animal *animal);
		void ConsumeFood(Animal *animal);
		
		Human h;
		Cat c;
		Animal a;
		Mammal m;
		Cat *ptC = &c;
};
