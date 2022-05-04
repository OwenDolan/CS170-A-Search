#include "../header/ASTAR.hpp"
#include <chrono>
//vector<Node*> visited;

bool ASTAR::isPrev(Node* curr, const vector<Node*> &visit) {
    int counter = 0;
    for (int k = 0; k < visit.size(); k++) {
        for (unsigned i = 0; i < curr->current_state.size(); i++) {
            for (unsigned j = 0; j < curr->current_state[i].size(); j++) {
                if (curr->current_state[i][j] == visit.at(k)->current_state[i][j]) {
                    counter++;
                }
            }
        }
    if (counter == 9) {
        return true;
    }
    counter=0;
    }

        return false;
}

struct HeuristicComparator
{
    bool operator()(Node const& lhs, Node const& rhs) const {
        return lhs.heuristicVal < rhs.heuristicVal;
            return true;
    }
};

Node* ASTAR::solve(Problem* p, int choice) {
    auto begin = high_resolution_clock::now();
    priority_queue<Node*, vector<Node*>, HeuristicComparator> nodes;
    vector<Node*> visited;
    Node* start = new Node;
    start->current_state = p->initial_state;
    start->heuristicVal = 1;
    start->findBlank();
    
    nodes.push(start);
    bool finished = false;
    bool failed;
    Node* curr = new Node;
    int loopCounter = 0;
    while (!finished) {
        if (nodes.empty()) {
            failed = true;
            cout << "!!operation failed!!" << endl;
            throw out_of_range("uh oj");
            break;
        }
        else {
            curr = nodes.top();
            nodes.pop();
        }
        if (!p->isGoal(curr)) {           //NEED TO CHANGE/GETRID OF BC IT RUINS UNIFORM SEARCH!!!!
            if (choice == 1) {  //choose which algorithm to use

                visited.push_back(curr);

                Node* newUp = new Node(curr);
                p->moveUp(newUp);
                newUp->findBlank();
                //newUp->heuristicVal++;
                if (!isPrev(newUp,visited)) {
                    nodes.push(newUp);    //push to frontier
                }

                Node* newDown = new Node(curr);
                p->moveDown(newDown);
                newDown->findBlank();
                //newDown->heuristicVal++;
                if (!isPrev(newDown, visited)) {
                    nodes.push(newDown);    //push to frontier
                }

                Node* newLeft = new Node(curr);
                p->moveLeft(newLeft);
                newLeft->findBlank();                
                //newLeft->heuristicVal++;
                if (!isPrev(newLeft, visited)) {
                    nodes.push(newLeft);    //push to frontier
                }

                Node* newRight = new Node(curr);
                p->moveRight(newRight);
                newRight->findBlank();
                //newRight->heuristicVal++;
                if (!isPrev(newRight,visited)) {
                    nodes.push(newRight);    //push to frontier
                }

            }
            else if (choice == 2) {

                visited.push_back(curr);
                Node* newUp = new Node(curr);
                p->moveUp(newUp); //perform operation
                newUp->findBlank(); //find where 0 lies update ipos and jpos
                p->misplacedTile(newUp);  //set misplacedTile heuristic
/*
                for (int i = 0; i < loopCounter; i++) { //add 1 for every level deep
                    newUp->heuristicVal++;
                }
                */
                if (!isPrev(newUp,visited)) {
                    nodes.push(newUp);    //push to frontier
                }
            
                Node* newDown = new Node(curr);
                p->moveDown(newDown);
                newDown->findBlank();
                p->misplacedTile(newDown);
            /*
                for (int i = 0; i < loopCounter; i++) {
                    newDown->heuristicVal++;
                }
                */
                if (!isPrev(newDown, visited)) {
                    nodes.push(newDown);    //push to frontier
                }

                Node* newLeft = new Node(curr);
                p->moveLeft(newLeft);
                newLeft->findBlank();
                p->misplacedTile(newLeft);
                /*
                for (int i =0; i < loopCounter; i++) {
                    newLeft->heuristicVal++;
                }
                    */
                if (!isPrev(newLeft, visited)) {
                    nodes.push(newLeft);    //push to frontier
                }
                
                Node* newRight = new Node(curr);
                p->moveRight(newRight);
                newRight->findBlank();
                p->misplacedTile(newRight);
                /*
                for (int i =0; i< loopCounter; i++) {
                    newRight->heuristicVal++;
                }
                */
                if (!isPrev(newRight,visited)) {
                    nodes.push(newRight);    //push to frontier
                }

                loopCounter++;
                
            }
            else if (choice == 3) {

                visited.push_back(curr);
                Node* newUp = new Node(curr);
                p->moveUp(newUp); //perform operation
                newUp->findBlank();
                p->euclidianDist(newUp);  //set misplacedTile heuristic
                //newUp->heuristicVal++;
                if (!isPrev(newUp,visited)) {
                    nodes.push(newUp);    //push to frontier
                }

                Node* newDown = new Node(curr);
                p->moveDown(newDown);
                newDown->findBlank();
                p->euclidianDist(newDown);
                //newDown->heuristicVal++;
                if (!isPrev(newDown, visited)) {
                    nodes.push(newDown);    //push to frontier
                }

                Node* newLeft = new Node(curr);
                p->moveLeft(newLeft);                
                newLeft->findBlank();
                p->euclidianDist(newLeft);
                //newLeft->heuristicVal++;
                if (!isPrev(newLeft, visited)) {
                    nodes.push(newLeft);    //push to frontier
                }
                
                Node* newRight = new Node(curr);
                p->moveRight(newRight);
                newRight->findBlank();
                p->euclidianDist(newRight);
                //newRight->heuristicVal++;
                if (!isPrev(newRight,visited)) {
                    nodes.push(newRight);    //push to frontier
                }
            }
        }
        else {
            finished = true; 
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - begin);
            cout << "Completed in " << duration.count() << " microseconds." << endl;
        }
    }
    return curr;
}

