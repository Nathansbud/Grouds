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
	void Eat() { std::cout << "Apex predator, nerds!" << std::endl; }
	void GiveBirth() { std::cout << "Sick, a baby!" << std::endl; }
};

#endif /* Human_hpp */
