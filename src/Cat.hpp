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
  void Eat() { std::cout << "Yum, milk" << std::endl; }
  void Move() {std::cout << "Look at these 4 paws I possess, man" << std::endl;}
};

#endif /* Cat_hpp */
