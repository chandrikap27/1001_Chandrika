#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct stack
{
    int top;
    int size;
    int *arr;
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
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
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

int main()
{
        int num,rem;
        struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
        sp->top=-1;
        sp->size=MAX;
        sp->arr=(int*)malloc(MAX*sizeof(char));
        printf("Enter an integer : ");
        scanf("%d",&num);
        printf("Binary Equivalent is : ");
         while(num!=0)
        {
                rem = num%2;
                push(sp,rem);
                num/=2;
        }
        while(sp->top!=-1)
                printf("%d", pop(sp));
        printf("\n");

        return 0;

}

