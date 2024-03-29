//
//  Entity.hpp
//  Testing Grouds
//
//  Created by Zack Amiton on 5/29/17.
//
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <map>
#include <vector>
#include <string>
//#include "ofVec2f.h"
#include "ofMain.h"

enum class EntityType
{
  HUMAN
};

class Entity
{
  public:
	Entity(){};
	Entity(EntityType e, int id);
	~Entity();
	
	virtual void Draw();
	virtual void Update();
	
	void SetPos(float posX, float posY);
	
	EntityType GetEntity() {return _entity;}
	std::string GetEntityS() {return _entityS.at(_entity);}
	
	void SetEntity(EntityType e) {_entity = e;}
	
	int GetID() {return _id;}
	void SetID(int id) { _id = id;}
  
	virtual void InitializeData();
	virtual void UpdateData();
	
	void AddData(std::string dat) {_data.push_back(dat);}
	void SetData(int index, std::string dat);
	std::string GetData(int index);
	int GetDataSize() {return _data.size();}
	
	ofVec2f GetPos() {return _pos;}
	ofVec2f GetSize() {return _size;}
	
	void SetSize(float posX, float posY);

	
  
  private:
	int _id;
	ofVec2f _pos;
	ofVec2f _size;

	EntityType _entity;
  
	std::vector<std::string> _data;
	const std::map<EntityType, std::string> _entityS = {{EntityType::HUMAN, "Human"}};
};



#endif /* Entity_hpp */
