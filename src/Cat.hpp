//
//  Cat.hpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/14/17.
//
//

#ifndef Cat_hpp
#define Cat_hpp

#include <iostream>
#include "Mammal.hpp"

class Cat : public Mammal
{
  Cat();
  ~Cat();
  void Eat();
  void Move();
};

#endif /* Cat_hpp */
