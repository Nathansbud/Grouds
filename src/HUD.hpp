//
//  HUD.hpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/23/17.
//
//

#ifndef HUD_hpp
#define HUD_hpp

#include <stdio.h>
#include <string>
#include <math.h>
#include "WorldMap.hpp"

class HUD
{
  public:
	HUD(WorldMap* map);
	~HUD();
	
	void GetInfo();
	void GetData(Tile* tile);
	void Draw();
	void Update();
	
  private:
	WorldMap* _map;
	std::string _name;
	std::string _type;
	int _size;
	int _id;
  
	
	ofVec2f _rightPos;
	ofVec2f _leftPos;
	
	
};


#endif /* HUD_hpp */
