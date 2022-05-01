#include "../header/Problem.hpp"

bool Problem::isGoal(Node* curr) {
    return false;
}
/*
void Problem::expand(Node* curr) {

}
*/
void Problem::moveUp(Node* curr) {
    int ipos = curr->ipos;
    int jpos = curr->jpos;
    if (curr->jpos == 0) {
        int temp = curr->current_state[ipos][jpos];
        if (temp != 0) {
            throw out_of_range("fucked logic");
        }
       curr->current_state[ipos][jpos] = curr->current_state[ipos][jpos+1];
       curr->current_state[ipos][jpos+1] = curr->current_state[ipos][jpos+2];
       curr->current_state[ipos][jpos+2] = temp;
    }
    else {
        int temp = curr->current_state[ipos][jpos];
        if (temp != 0) {
            throw out_of_range("fucked logic");
        }
        curr->current_state[ipos][jpos] = curr->current_state[ipos][jpos-1];
        curr->current_state[ipos][jpos-1] = temp;
    }
}
void Problem::moveDown(Node* curr) {
    int ipos = curr->ipos;
    int jpos = curr->jpos;
    if (curr->jpos == 2) {
        int temp = curr->current_state[ipos][jpos];
        if (temp != 0) {
            throw out_of_range("fucked logic");
        }
       curr->current_state[ipos][jpos] = curr->current_state[ipos][jpos-1];
       curr->current_state[ipos][jpos-1] = curr->current_state[ipos][jpos-2];
       curr->current_state[ipos][jpos-2] = temp;
    }
    else {
        int temp = curr->current_state[ipos][jpos];
        if (temp != 0) {
            throw out_of_range("fucked logic");
        }
        curr->current_state[ipos][jpos] = curr->current_state[ipos][jpos+1];
        curr->current_state[ipos][jpos+1] = temp;
    }
}

void Problem::moveLeft(Node* curr) {
    int ipos = curr->ipos;
    int jpos = curr->jpos;
    if (curr->ipos == 0) {
        int temp = curr->current_state[ipos][jpos];
        if (temp != 0) {
            throw out_of_range("fucked logic");
        }
       curr->current_state[ipos][jpos] = curr->current_state[ipos+1][jpos];
       curr->current_state[ipos+1][jpos] = curr->current_state[ipos+2][jpos];
       curr->current_state[ipos+2][jpos] = temp;
    }
    else {
        int temp = curr->current_state[ipos][jpos];
        if (temp != 0) {
            throw out_of_range("fucked logic");
        }
        curr->current_state[ipos][jpos] = curr->current_state[ipos-1][jpos];
        curr->current_state[ipos-1][jpos] = temp;
    }
}

void Problem::moveRight(Node* curr) {
    int ipos = curr->ipos;
    int jpos = curr->jpos;
    if (curr->ipos == 2) {
        int temp = curr->current_state[ipos][jpos];
        if (temp != 0) {
            throw out_of_range("fucked logic");
        }
       curr->current_state[ipos][jpos] = curr->current_state[ipos-1][jpos];
       curr->current_state[ipos-1][jpos] = curr->current_state[ipos-2][jpos];
       curr->current_state[ipos-2][jpos] = temp;
    }
    else {
        int temp = curr->current_state[ipos][jpos];
        if (temp != 0) {
            throw out_of_range("fucked logic");
        }
        curr->current_state[ipos][jpos] = curr->current_state[ipos+1][jpos];
        curr->current_state[ipos+1][jpos] = temp;
    }
}


void Problem::misplacedTile(Node* curr) {
    int counter = 1;
    int misplaced = 0;
    for (unsigned i = 0; i < curr->current_state.size(); i++) {
        for (unsigned j = 0; j < curr->current_state[i].size(); j++) {
            if (curr->current_state[j][i] != counter) {
                misplaced++;
                counter++;
            }
            else {
                counter++;
            }
        }
    }
    curr->heuristicVal += misplaced;
}

void Problem::euclidianDist(Node* curr) {   //want # of spaces each tile is away from home = abs(i2 - i1) + abs(j2 - j1)
    int dist = 0;
    for (unsigned i = 0; i < curr->current_state.size(); i++) {
        for (unsigned j = 0; j < curr->current_state[i].size(); j++) {
            if(curr->current_state[i][j] == 1) {
                dist += calcDist(i,j,0,0);
            }
            else if (curr->current_state[i][j] == 2) {
                dist += calcDist(i,j,1,0);
            }
            else if (curr->current_state[i][j] == 3) {
                dist += calcDist(i,j,2,0);
            }
            else if (curr->current_state[i][j] == 4) {
                dist += calcDist(i,j,0,1);
            }
            else if (curr->current_state[i][j] == 5) {
                dist += calcDist(i,j,1,1);
            }
            else if (curr->current_state[i][j] == 6) {
                dist += calcDist(i,j,2,1);
            }
            else if (curr->current_state[i][j] == 7) {
                dist += calcDist(i,j,0,2);
            }
            else if (curr->current_state[i][j] == 8) {
                dist += calcDist(i,j,1,2);
            }
        }
    }
    curr->heuristicVal += dist;
}

int Problem::calcDist(int i,int j, int i2, int j2) {
    return abs(i2-i) + abs(j2-j);
}

