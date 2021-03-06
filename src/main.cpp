#include <iostream>
#include "../header/ASTAR.hpp"

using namespace std;

void initialize(Problem* p, int choice) {

    vector<vector<int> > init {
        {1, 0, 3}, {4, 2, 6}, {7,5,8}
    };
    vector<vector<int> > goal {
        {1, 2, 3}, {4,5,6}, {7,8,0} 
    };

    vector<vector<int> > init1;

/*
    goal[0][0] = 1;
    goal[1][0] = 2;
    goal[2][0] = 3;
    goal[0][1] = 4;
    goal[1][1] = 5;
    goal[2][1] = 6;
    goal[0][2] = 7;
    goal[1][2] = 8;
*/


    if (choice == 1) {
        p->initial_state = init;
        p->goal_state = goal;
    }
    else {
        p->goal_state = goal;
        cout << "Enter your puzzle, use a 0 to represent the blank" << endl;

        int num;
        for (unsigned i = 0; i < 3; i++) {
            if (i == 0) {
                    cout << "Enter the first row, pressing ENTER after each digit entry: " << flush;
                }
                else if (i == 1) {
                    cout << "Enter the second row, pressing ENTER after each digit entry: " << flush;
                }
                else if (i == 2) {
                    cout << "Enter the third row, pressing ENTER after each digit entry: " << flush;
                }
                vector<int> row;

            for (unsigned j = 0; j < 3; j++) {
                cin >> num;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "invalid input. please try again" << endl;
                    cin >> num;
                }
                row.push_back(num);
            }
            init1.push_back(row);
        }

        p->initial_state = init1;

    }
}

void printSol(Node *sol) {
    if (sol == nullptr) {
        return;
    }
    printSol(sol->parent_ptr);
    cout << endl;

    for (unsigned i = 0; i < sol->current_state.size(); i++) {
        for (unsigned j = 0; j < sol->current_state[i].size(); j++) {
            cout << sol->current_state[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    Problem *p = new Problem;
    int choice;

    cout << "Welcome to 862102456 8-puzzle solver!" << endl;
    cout << "Enter 1 for default puzzle or 2 to enter your own: " << flush;

    cin >> choice;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "invalid input. please try again" << endl;
        cin >> choice;
    }

    if (choice == 1) {
        initialize(p, choice);
    }
    else if (choice == 2) {
        initialize(p, choice);
    }
    else {
        cout << "invalid input. please exit program and try again :(" << endl;
    }

    cout << "Enter your choice of algorithm" << endl;
    cout << "1. Uniform Cost Search\n2. A* with the Misplaced Tile heuristic\n3. A* with the Euclidian distance heuristic" << endl;
    cin >> choice;

    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "invalid input. please try again" << endl;
        cin >> choice;
    }
    ASTAR *a;
    Node* sol = a->solve(p, choice);
    printSol(sol);



    return 0;
}