//
//  HUD.hpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/23/17.
//
//

#ifndef HUD_hpp
#define HUD_hpp

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
//	void CastData(Tile* tile);
		
  private:
	WorldMap* _map;
	std::string _name;
	std::string _type;
	int _size;
	int _id;
	
	Tile* _moused;
	Tile* _selected;
	
//	TTree *tree;
//	TRock *rock;
//	THuman *human;
	
	
  
	
	ofVec2f _rightPos;
	ofVec2f _leftPos;
	float _sElement(int num) {return _rightPos.y + ofGetHeight()/30 * num;}
	float _mElement(int num) {return _rightPos.y + ofGetHeight()/3 + ofGetHeight()/30 * num;}
	
	
};


#endif /* HUD_hpp */
