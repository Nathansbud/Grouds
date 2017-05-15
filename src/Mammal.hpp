//
//  Mammal.hpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/14/17.
//
//

#ifndef Mammal_hpp
#define Mammal_hpp

#include <iostream>
#include "Animal.hpp"

class Mammal : public Animal
{
  public:
	Mammal();
	~Mammal();
  
	virtual void GiveBirth(){};
	bool isAlive();
	
	bool isHeartbeating;
	
	void Move();
};

#endif /* Mammal_hpp */
