//
//  Animal.hpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/14/17.
//
//

#ifndef Animal_hpp
#define Animal_hpp

#include <iostream>
#include <stdio.h>

class Animal
{
  public:
	Animal();
	~Animal();
	virtual void Eat() {std::cout << "Yum look at dis food" << std::endl;}
	virtual void Move() {std::cout << "Motion" << std::endl;}
	virtual bool isAlive(){}
};


#endif /* Animal_hpp */
