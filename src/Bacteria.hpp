//
//  Bacteria.hpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/15/17.
//
//

#ifndef Bacteria_hpp
#define Bacteria_hpp

#include <stdio.h>
#include "Animal.hpp"

class Bacteria : public Animal
{
  public:
  	enum Disease{Malaria};
	Bacteria(Disease disease);
	~Bacteria();
	void Eat();
	void Move();
	std::string type;
};


#endif /* Bacteria_hpp */
