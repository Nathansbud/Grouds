#include "ofApp.h"

void ofApp::setup()
{
  ConsumeFood(&c);
  ConsumeFood(&h);
  ConsumeFood(&m);
  ConsumeFood(&a);
  Movement(&c);
  Movement(&h);
  Movement(&m);
  Movement(&a);
}

void ofApp::update(){

}

void ofApp::draw(){

}

void ofApp::ConsumeFood(Animal *animal)
{
  animal->Eat();
}

void ofApp::Movement(Animal *animal)
{
  animal->Move();
}
