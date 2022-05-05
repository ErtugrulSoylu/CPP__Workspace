#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20


//initializing array implemented stack
float Stack[N]; 
int Top = -1; //Top value is index of top element

//stack gets a new element and Top index increases by one
void push(float val) { 
    if(Top == N) printf("Stack is full\n"); //when Top index hits to max stack can't hold more elements
    else {
        Top++;
        Stack[Top] = val;
    }
    return;
}
float pop() { //decreases Top index by one and returns old Top element
    if(Top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        float popped_val = Stack[Top];
        Top--;
        return popped_val;
    }
}
int main() {
    printf("To finish, enter word \"end\".\n\n");
    while(1) {
        char token[50];
        printf("Enter a token: ");
        scanf("%s",token);
        //if is +, -
        if (!strcmp(token,"end")){ 
            float result=pop();
            printf("\nResult is %.2f",result);
            return 0;
        } else if (!strcmp(token,"+")){ 
            float tmp = pop();
            Stack[Top] += tmp;
        } else if (!strcmp(token,"-")){
            float tmp = pop();
            Stack[Top] -= tmp;
        } else if (!strcmp(token,"/")){ 
            float tmp = pop();
            Stack[Top] /= tmp;
        } else if (!strcmp(token,"*")){ 
            float tmp = pop();
            Stack[Top] *= tmp;
        } else push (atof(token));
    }
    return 0;
}