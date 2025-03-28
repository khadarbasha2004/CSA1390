#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 10

// Function to compute e-closure using Depth-First Search (DFS)
void dfs(int state, int epsilon[MAX_STATES][MAX_STATES], int *visited, int *closure) {
    // Mark the current state as visited and part of the closure
    visited[state] = 1;
    closure[state] = 1;  // Add the state to its e-closure

    // Explore all states reachable by e-transitions
    for (int nextState = 0; nextState < MAX_STATES; nextState++) {
        if (epsilon[state][nextState] == 1 && !visited[nextState]) {
            // Recursively visit the next state via e-transition
            dfs(nextState, epsilon, visited, closure);
        }
    }
}

// Function to calculate the e-closure for each state
void calculateEpsilonClosure(int epsilon[MAX_STATES][MAX_STATES], int numStates) {
    for (int state = 0; state < numStates; state++) {
        int visited[MAX_STATES] = {0};  // To track visited states
        int closure[MAX_STATES] = {0};  // To store the e-closure for the current state
        
        // Calculate the e-closure using DFS
        dfs(state, epsilon, visited, closure);
        
        // Print the e-closure for the current state
        printf("e-closure(%d) = { ", state);
        for (int i = 0; i < numStates; i++) {
            if (closure[i]) {
                printf("%d ", i);
            }
        }
        printf("}\n");
    }
}

int main() {
    int epsilon[MAX_STATES][MAX_STATES] = {0};  // e-transition matrix
    int numStates;

    // Input the number of states in the NFA
    printf("Enter the number of states in the NFA: ");
    scanf("%d", &numStates);

    // Input the e-transitions
    printf("Enter the e-transitions (state1 state2):\n");
    printf("For each pair (state1, state2), enter an e-transition. Enter -1 -1 to stop input.\n");

    int state1, state2;
    while (1) {
        printf("Enter state1 and state2: ");
        scanf("%d %d", &state1, &state2);
        if (state1 == -1 && state2 == -1) {
            break;
        }
        // Mark e-transition from state1 to state2
        epsilon[state1][state2] = 1;
    }

    // Calculate and display e-closures for all states
    calculateEpsilonClosure(epsilon, numStates);

    return 0;
}

