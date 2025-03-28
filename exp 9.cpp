#include <stdio.h>
#include <string.h>
int simulateNFA(char* input) {
    int len = strlen(input);
    int state = 0; 
    for (int i = 0; i < len; i++) {
        char currentChar = input[i];

        switch (state) {
            case 0:
                if (currentChar == '0') {
                    state = 1; 
                } else {
                    return 0; 
                }
                break;
            case 1:
                if (currentChar == '1') {
                    state = 2; 
                }
                break;
            case 2: 
                return 0; 
        }
    }
    if (state == 2) {
        return 1; 
    }
    return 0; 
}

int main() {
    char input[100];

    printf("Enter the string: ");
    scanf("%s", input);
    if (simulateNFA(input)) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is rejected by the NFA.\n");
    }

    return 0;
}

