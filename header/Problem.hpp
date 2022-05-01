
#ifndef PROBLEM_HPP_
#define PROBLEM_HPP_
#endif

//#pragma once

#include "Node.hpp"
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Node;
class Problem {

public:

vector<vector<int> > initial_state;
vector<vector<int> > goal_state;
 
//int initial_state[3][3];
//int goal_state[3][3];
//int **goal_state = new int*[3];

bool isGoal( Node &curr);
//void expand(Node* curr);
void moveUp( Node &curr);
void moveDown( Node &curr);

void moveLeft( Node &curr);
void moveRight( Node &curr);

void misplacedTile( Node &curr);
void euclidianDist( Node &curr);

void findBlank( Node &curr, int &ipos, int &jpos);   //helper function to find space on board

private:

int calcDist(int i,int j, int i2, int i3);
};