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
#include "Mammal.hpp"

class Human : public Mammal
{
  public:
	Human();
	~Human();
	void Eat();
	void Move();
	void GiveBirth();
};

#endif /* Human_hpp */
