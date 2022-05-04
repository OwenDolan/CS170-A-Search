#ifndef ASTAR_HPP_
#define ASTAR_HPP_
#endif

#include "../header/Problem.hpp"
#include "../header/Node.hpp"

#include <queue>
#include <iostream>

using namespace std;

class ASTAR {
public:
vector<Node*> visited;
Node* solve(Problem* p, int choice);
bool isPrev(Node* curr, const vector<Node*> &visit);

private:

};