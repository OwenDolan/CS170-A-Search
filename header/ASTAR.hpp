#ifndef ASTAR_HPP_
#define ASTAR_HPP_
#endif

#include "../header/Problem.hpp"
#include "../header/Node.hpp"

#include <queue>
#include <iostream>

using namespace std;

struct HeuristicComparator
{
    bool operator()(const Node* lhs, const Node* rhs) const {
        if (lhs->heuristicVal < rhs->heuristicVal) {
            return true;
        }
        else {
            return false;
        }
    }
};

class ASTAR {
public:

Node* solve(Problem* p, int choice);

private:

};