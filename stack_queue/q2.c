#include<stdio.h>
#include<stdlib.h>
 
struct Node{
    int data_1001;
    struct Node * next_1001;
};
 
struct Node* top_1001 = NULL;
 
void linkedListTraversal(struct Node *ptr_1001)
{
    printf("\nElements left in stack: \n");
    while (ptr_1001 != NULL)
    {
        printf("Element: %d\n", ptr_1001->data_1001);
        ptr_1001 = ptr_1001->next_1001; 
    }
}
 
int isEmpty(struct Node* top_1001){
    if (top_1001==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
int isFull(struct Node* top_1001){
    struct Node* p_1001 = (struct Node*)malloc(sizeof(struct Node));
    if(p_1001==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
struct Node* push(struct Node* top_1001, int x_1001){
    if(isFull(top_1001)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n_1001 = (struct Node*) malloc(sizeof(struct Node));
        n_1001->data_1001 = x_1001;
        n_1001->next_1001 = top_1001;
        top_1001 = n_1001;
        return top_1001;
    }
}
 
int pop(struct Node* tp_1001){
    if(isEmpty(tp_1001)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n_1001 = tp_1001;
        top_1001 = (tp_1001)->next_1001;
        int x_1001 = n_1001->data_1001;
        free(n_1001);
        return x_1001; 
    }
}
 
int main()
{
    int c_1001=1,ele_1001;
   while(c_1001)
    {
        printf("enter the element you want to insert: ");
        scanf("%d",&ele_1001);
        top_1001=push(top_1001,ele_1001);
        printf("Do you want to continue ?? 1 for Yes 0 for No : ");
        scanf("%d", &c_1001);
        getchar();
    }
   
    printf("Do you want to pop elements ?? 1 for Yes 0 for No : ");
    scanf("%d", &c_1001);
    while(c_1001)
    {
       printf("Popped %d from the stack\n", pop(top_1001)); 
        printf("Do you want to continue ?? 1 for Yes 0 for No : ");
        scanf("%d", &c_1001);
        getchar();
    }
    linkedListTraversal(top_1001);
    return 0;
}
