#include <stdio.h>
#include <string.h>

int trans_table[10][5][3];
int e_closure[10][10];       

void find_e_closure(int state, int num_states);

int main() 
{
    int num_states, num_symbols, i, j, k, n;

    printf("Enter the number of states in the NFA with epsilon moves: ");
    scanf("%d", &num_states); 

    printf("Enter the number of symbols (including epsilon): ");
    scanf("%d", &num_symbols);
    for(i = 0; i < num_states; i++) 
    { 
        for(j = 0; j < num_symbols; j++) 
        { 
            printf("How many transitions from state %d for the input '%d': ", i, j); 
            scanf("%d", &n); 
            for(k = 0; k < n; k++) 
            { 
                printf("Enter the transition state %d for input '%d' from state %d: ", k + 1, j, i); 
                scanf("%d", &trans_table[i][j][k]); 
            } 
        }
    }
    for(i = 0; i < num_states; i++) 
        e_closure[i][0] = i;
    for(i = 0; i < num_states; i++) 
    {
        find_e_closure(i, num_states);
    }
    for(i = 0; i < num_states; i++) 
    {
        printf("e-closure(%d) = {", i);
        for(j = 0; j < num_states; j++) 
        {
            if(e_closure[i][j] != -1) 
                printf("%d ", e_closure[i][j]);
        }
        printf("}\n");
    }

    return 0;
}
void find_e_closure(int state, int num_states) 
{
    int i, j, next_state;
    for(i = 0; trans_table[state][0][i] != -1; i++) 
    {
        next_state = trans_table[state][0][i];
        if(e_closure[state][num_states] == -1) 
        {
            e_closure[state][num_states++] = next_state;\
            find_e_closure(next_state, num_states);
        }
    }
}

