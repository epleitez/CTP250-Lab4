//
// Created by Emely Pleitez on 9/30/22.
//

#include "Node.h"
Node::Node()
{
    //ctor
    next = nullptr;  //when new node created, next points to nothing
}
Node::~Node()
{
    //dtor
}
void Node::setValue(int value){
    this->value = value;
}
int Node::getValue(){
    return value;
}
