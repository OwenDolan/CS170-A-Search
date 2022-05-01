#ifndef NODE_HPP_
#define NODE_HPP_
#endif
#pragma once

#include <vector>
#include <exception>

using namespace std;
class Node {

public:
vector< vector<int> > current_state;
Node* parent_ptr;

int heuristicVal = 0;   //h(x) value
int ipos = -1;   //ith pos of space 
int jpos = -1;   //jth pos of space

Node() {
    parent_ptr = nullptr;
    //heuristicVal = 0;
    //findBlank();
}
/*
Node(Problem* p1) {  //constructor for initialize start node
    current_state = p1->initial_state;
    parent_ptr = nullptr;
    heuristicVal = 0;
    findBlank();

}
*/
Node(Node* curr) {   //gets passed new state after operation from EXPAND
    current_state = curr->current_state;
    parent_ptr = curr;
    heuristicVal = 1;   //cost of 1 for g(n)
    ipos = curr->ipos;
    jpos = curr->jpos;
}

void findBlank();

private:


};