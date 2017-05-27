//
//  Human.hpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/14/17.
//
//

#ifndef Human_hpp
#define Human_hpp

#include <stdio.h>
#include <iostream>
#include "Tile.hpp"

class THuman : public Tile
{
  public:
	THuman(TileType type, int id);
	~THuman();
	
	virtual void SetData();


	void Eat();
	void Move();
	void GiveBirth();
};

#endif /* Human_hpp */
