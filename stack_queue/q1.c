#include<stdio.h>
#include<stdlib.h>
 
struct stack{
    int size_1001 ;
    int top_1001;
    int * arr_1001;
};
 
int isEmpty(struct stack* ptr_1001){
    if(ptr_1001->top_1001 == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull(struct stack* ptr_1001){
    if(ptr_1001->top_1001 == ptr_1001->size_1001 - 1){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push(struct stack* ptr_1001, int val_1001){
    if(isFull(ptr_1001)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val_1001);
    }
    else{
        ptr_1001->top_1001++;
        ptr_1001->arr_1001[ptr_1001->top_1001] = val_1001;
    }
}
 
int pop(struct stack* ptr_1001){
    if(isEmpty(ptr_1001)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val_1001 = ptr_1001->arr_1001[ptr_1001->top_1001];
        ptr_1001->top_1001--;
        return val_1001;
    }
}
 
int main(){
    struct stack *sp_1001 = (struct stack *) malloc(sizeof(struct stack));
    sp_1001->size_1001 = 5;
    sp_1001->top_1001 = -1;
    sp_1001->arr_1001 = (int *) malloc(sp_1001->size_1001 * sizeof(int));
    int c_1001=1,ele_1001;
    printf("Stack has been created successfully\n");

    while(c_1001)
    {
        printf("enter the element you want to insert: ");
        scanf("%d",&ele_1001);
        push(sp_1001,ele_1001);
        printf("Do you want to continue ?? 1 for Yes 0 for No : ");
        scanf("%d", &c_1001);
        getchar();
    }
    printf("After pushing, Full: %d\n", isFull(sp_1001));
    printf("After pushing, Empty: %d\n", isEmpty(sp_1001));
    printf("Do you want to pop elements ?? 1 for Yes 0 for No : ");
    scanf("%d", &c_1001);
    while(c_1001)
    {
       printf("Popped %d from the stack\n", pop(sp_1001)); 
        printf("Do you want to continue ?? 1 for Yes 0 for No : ");
        scanf("%d", &c_1001);
        getchar();
    }
   
    return 0;
}
 