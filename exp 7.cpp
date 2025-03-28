#include <stdio.h>
#include <string.h>
int checkA(char *str, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return 0; 
        }
    }
    return 1; 
}
int checkS(char *str, int start, int end) {
    if (end - start + 1 < 3) {
        return 0;
    }

    int mid = (start + end) / 2;
    if (str[mid - 1] == '1' && str[mid] == '0' && str[mid + 1] == '1') {
        if (checkA(str, start, mid - 2) && checkA(str, mid + 2, end)) {
        }
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

