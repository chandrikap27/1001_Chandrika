#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    int priority;
    struct node *next;

} Node;
Node *newNode(int d, int p)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}
int peek(Node **head)
{
    return (*head)->data;
}
void pop(Node **head)
{
    Node *temp = *head;
    (*head) = (*head)->next;
    free(temp);
}
void push(Node **head, int d, int p)
{
    Node *start = (*head);
    Node *temp = newNode(d, p);
    if ((*head)->priority < p)
    {
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        while (start->next != NULL && start->next->priority > p)
        {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}
int isEmpty(Node **head)
{
    return (*head) == NULL;
}
int main()
{
    int size, ele, pri;
    printf("enter the size : ");
    scanf("%d", &size);
    Node *pq;
    printf("enter the element and its priority : ");
    scanf("%d%d", &ele, &pri);
    pq = newNode(ele, pri);
    for (int i = 1; i < size; i++)
    {
        printf("enter the element and its priority : ");
        scanf("%d%d", &ele, &pri);
        push(&pq, ele, pri);
    }

    while (!isEmpty(&pq))
    {
        printf("%d ", peek(&pq));
        pop(&pq);
    }

    return 0;
}