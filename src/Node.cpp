#include "../header/Node.hpp"

void Node::findBlank() {

    ipos = -1;  //set to test
    jpos = -1;

    for (unsigned i = 0; i < current_state.size(); i++) {
        for (unsigned j = 0; j < current_state[i].size(); j++) {
            if (current_state[i][j] == 0) {
                ipos = i;
                jpos = j;
            }

        }
    }
    if (ipos == -1 || jpos == -1) {
        throw out_of_range("uh oh");
    }
}