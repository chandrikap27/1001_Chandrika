#include<stdio.h>
#include<stdlib.h>
 
struct stack{
    int size ;
    int top;
    int * arr;
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
 
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
 
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    int c=1,ele;
    printf("Stack has been created successfully\n");

    while(c)
    {
        printf("enter the element you want to insert: ");
        scanf("%d",&ele);
        push(sp,ele);
        printf("Do you want to continue ?? 1 for Yes 0 for No : ");
        scanf("%d", &c);
        getchar();
    }
    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));
    printf("Do you want to pop elements ?? 1 for Yes 0 for No : ");
    scanf("%d", &c);
    while(c)
    {
       printf("Popped %d from the stack\n", pop(sp)); 
        printf("Do you want to continue ?? 1 for Yes 0 for No : ");
        scanf("%d", &c);
        getchar();
    }
   
    return 0;
}
 