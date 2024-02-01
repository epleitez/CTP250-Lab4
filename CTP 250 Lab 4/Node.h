//
// Created by Emely Pleitez on 9/30/22.
//

#ifndef CTP_250_LAB_4_NODE_H
#define CTP_250_LAB_4_NODE_H


class Node {   //Node can be anything
public:
    Node();
    virtual ~Node();
    Node *next;  //link to another node of same type
    void setValue(int);
    int getValue();
private:
    int value;  //the data value in the node
};


#endif //CTP_250_LAB_4_NODE_H
