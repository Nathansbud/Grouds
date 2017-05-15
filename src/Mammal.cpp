//
//  Mammal.cpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/14/17.
//
//

#include "Mammal.hpp"

Mammal::Mammal()
{
  isHeartbeating = true;
}

Mammal::~Mammal()
{

}

bool Mammal::isAlive()
{
  isHeartbeating ? 1 : 0;
}
