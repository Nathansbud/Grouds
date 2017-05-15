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
  
	virtual void GiveBirth()
	{
	  std::cout << "Sick, a smaller me!" << std::endl;
	}
	
	bool isAlive();
	
	bool isHeartbeating;
	
	void Move() { std::cout << "And so I walk."  << std::endl; } 
	
};

#endif /* Mammal_hpp */
