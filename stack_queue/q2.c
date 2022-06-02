#include<stdio.h>
#include<stdlib.h>
 
struct Node{
    int data;
    struct Node * next;
};
 
struct Node* top = NULL;
 
void linkedListTraversal(struct Node *ptr)
{
    printf("\nElements left in stack: \n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
}
 
int isEmpty(struct Node* top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
struct Node* push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
 
int pop(struct Node* tp){
    if(isEmpty(tp)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}
 
int main()
{
    int c=1,ele;
   while(c)
    {
        printf("enter the element you want to insert: ");
        scanf("%d",&ele);
        top=push(top,ele);
        printf("Do you want to continue ?? 1 for Yes 0 for No : ");
        scanf("%d", &c);
        getchar();
    }
   
    printf("Do you want to pop elements ?? 1 for Yes 0 for No : ");
    scanf("%d", &c);
    while(c)
    {
       printf("Popped %d from the stack\n", pop(top)); 
        printf("Do you want to continue ?? 1 for Yes 0 for No : ");
        scanf("%d", &c);
        getchar();
    }
    linkedListTraversal(top);
    return 0;
}
