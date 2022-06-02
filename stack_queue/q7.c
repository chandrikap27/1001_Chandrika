#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data_1001;
    int priority_1001;
    struct node* next_1001;
 
} Node;
Node* newNode(int d_1001, int p_1001)
{
    Node* temp_1001 = (Node*)malloc(sizeof(Node));
    temp_1001->data_1001 = d_1001;
    temp_1001->priority_1001 = p_1001;
    temp_1001->next_1001 = NULL;
    return temp_1001;
}
int peek(Node** head_1001)
{
    return (*head_1001)->data_1001;
}
void pop(Node** head_1001)
{
    Node* temp_1001 = *head_1001;
    (*head_1001) = (*head_1001)->next_1001;
    free(temp_1001);
}
void push(Node** head_1001, int d_1001, int p_1001)
{
    Node* start_1001 = (*head_1001);
    Node* temp_1001 = newNode(d_1001, p_1001);
    if ((*head_1001)->priority_1001 > p_1001) {
         temp_1001->next_1001 = *head_1001;
        (*head_1001) = temp_1001;
    }
    else {
        while (start_1001->next_1001 != NULL &&
            start_1001->next_1001->priority_1001 < p_1001) {
            start_1001 = start_1001->next_1001;
        }
         temp_1001->next_1001 = start_1001->next_1001;
        start_1001->next_1001 = temp_1001;
    }
}
int isEmpty(Node** head_1001)
{
    return (*head_1001) == NULL;
}
int main()
{
    Node* pq_1001 = newNode(43, 1);
    push(&pq_1001, 68, 2);
    push(&pq_1001, 98, 3);
    push(&pq_1001, 27, 0);
 
    while (!isEmpty(&pq_1001)) {
        printf("%d ", peek(&pq_1001));
        pop(&pq_1001);
    }
 
    return 0;
}