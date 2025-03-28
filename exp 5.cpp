#include <stdio.h>
#include <string.h>
int checkS(char *str, int start, int end) {
    if (start > end) {
        return 1;
    }

    if (str[start] == '0' && str[end] == '0') {
        return checkS(str, start + 1, end - 1);
    }
    return checkS(str, start, end);
}
int checkA(char *str, int start, int end) {
    if (start > end) {
        return 1;
    }
    if (str[start] == '1') {
        return checkA(str, start + 1, end);
    }
    return 0;
}

int main() {
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);
    
    int len = strlen(str);
    if (checkS(str, 0, len - 1)) {
        printf("The string belongs to the language.\n");
    } else {
        printf("The string does not belong to the language.\n");
    }

    return 0;
}

