//
//  Entity.cpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/29/17.
//
//

#include "Entity.hpp"

Entity::Entity(EntityType e, int id)
{
  SetEntity(e);
  SetID(id);
  
}

Entity::~Entity()
{

}



void Entity::Draw()
{
  ofFill();
  switch(GetEntity())
  {
	case EntityType::HUMAN:
	  ofSetColor(133, 94, 66);
	  break;
  }
  ofDrawEllipse(_pos, _size.x, _size.y);
  ofNoFill();
}

void Entity::Update()
{
  UpdateData();
}

void Entity::SetSize(float posX, float posY)
{
  _size = ofVec2f(posX, posY);
}


void Entity::SetPos(float posX, float posY)
{
  _pos = ofVec2f(posX, posY);
}

void Entity::SetData(int index, std::string dat)
{
  _data.at(index) = dat;
}

void Entity::InitializeData()
{
  AddData("Tile #" + std::to_string(GetID()));
  AddData(GetEntityS());
}
void Entity::UpdateData()
{
  SetData(0, "Tile #" + std::to_string(GetID()));
  SetData(1, GetEntityS());
}

std::string Entity::GetData(int index)
{
  return _data.at(index);
}
