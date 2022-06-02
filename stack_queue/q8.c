#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int top;
    int size;
    char *arr;
};
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
void main(){
    char str[50];
    printf("enter string : ");
    gets(str);
    printf("reversed string : ");
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->top=-1;
    sp->size=strlen(str);
    sp->arr=(char*)malloc(strlen(str)*sizeof(char));
    int i=0;
    while(str[i]!='\0')
    {
        push(sp,str[i]);
        i++;
    }
    while(sp->top!=-1)
    {
        printf("%c",pop(sp));
    }
}
