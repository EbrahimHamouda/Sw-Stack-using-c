#include <stdio.h>
#include <stdlib.h>
#include "sw_stack_array.h"
#include "test_cases.h"

#define MAX_STACK 5
#define MAX_DATA 6
#define N_PUSH 3
#define N_POP  5

gStrStack_t mystack;
gStrData_t BUFFER;
gStrData_t myData[MAX_DATA]= {{"mohamed",1,1.1},{"ahmed",2,1.2},{"mostafa",3,1.3},{"khaled",4,1.4},{"gamal",5,1.5},{"ali",6,1.6}};

int main(void)
{

    create_stack(&mystack,MAX_STACK);

    test_push(N_PUSH,&mystack,myData);

    test_pop(N_POP,&mystack,&BUFFER);

    print_buffer(&BUFFER);

    return 0;
}

