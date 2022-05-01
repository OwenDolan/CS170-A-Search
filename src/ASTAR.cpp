#include "../header/ASTAR.hpp"

struct HeuristicComparator
{
    bool operator()(Node const& lhs, Node const& rhs) const {
        return lhs.heuristicVal > rhs.heuristicVal;
            return true;
    }
};

const Node& ASTAR::solve(Problem* p, int choice) {
    priority_queue<Node, vector<Node>, HeuristicComparator> nodes;
    Node* start = new Node;
    start->current_state = p->initial_state;
    start->heuristicVal = 1;
    start->findBlank();
    
    nodes.push(start);
    bool finished = false;
    bool failed;
    Node curr = new Node;
    while (!finished) {
        if (nodes.empty()) {
            failed = true;
            cout << "!!operation failed!!" << endl;
            break;
        }
        else {
            curr = nodes.top();
            nodes.pop();
        }
        if (!p->isGoal(curr)) {           //NEED TO CHANGE/GETRID OF BC IT RUINS UNIFORM SEARCH!!!!
            if (choice == 1) {  //choose which algorithm to use
                Node newUp = new Node(curr);
                p->moveUp(newUp);
                newUp.findBlank();
                nodes.push(newUp);

                Node newDown = new Node(curr);
                p->moveDown(newDown);
                newDown.findBlank();
                nodes.push(newDown);

                Node newLeft = new Node(curr);
                p->moveLeft(newLeft);
                newLeft.findBlank();
                nodes.push(newLeft);

                Node newRight = new Node(curr);
                p->moveRight(newRight);
                newRight.findBlank();
                nodes.push(newRight);

            }
            else if (choice == 2) {
                Node newUp = new Node(curr);
                p->moveUp(newUp); //perform operation
                newUp.findBlank();
                p->misplacedTile(newUp);  //set misplacedTile heuristic
                nodes.push(newUp);    //push to frontier

                Node newDown = new Node(curr);
                p->moveDown(newDown);
                newDown.findBlank();
                p->misplacedTile(newDown);
                nodes.push(newDown);

                Node newLeft = new Node(curr);
                p->moveLeft(newLeft);
                newLeft.findBlank();
                p->misplacedTile(newLeft);
                nodes.push(newLeft);
                
                Node newRight = new Node(curr);
                p->moveRight(newRight);
                newRight.findBlank();
                p->misplacedTile(newRight);
                nodes.push(newRight);
                
            }
            else if (choice == 3) {
                Node newUp = new Node(curr);
                p->moveUp(newUp); //perform operation
                newUp.findBlank();
                p->euclidianDist(newUp);  //set misplacedTile heuristic
                nodes.push(newUp);    //push to frontier

                Node newDown = new Node(curr);
                p->moveDown(newDown);
                newDown.findBlank();
                p->euclidianDist(newDown);
                nodes.push(newDown);

                Node newLeft = new Node(curr);
                p->moveLeft(newLeft);                
                newLeft.findBlank();
                p->euclidianDist(newLeft);
                nodes.push(newLeft);
                
                Node newRight = new Node(curr);
                p->moveRight(newRight);
                newRight.findBlank();
                p->euclidianDist(newRight);
                nodes.push(newRight);
            }
        }
        else {
            finished = true; 
            return curr;
        }
    }
}

