
#include <stdio.h>
#include<stdlib.h>
#define MAX 30
typedef struct dequeue
{
    int data[MAX];
    int rear, front;
} dequeue;
void initialize(dequeue *P)
{
    P->rear = -1;
    P->front = -1;
}
int empty(dequeue *P)
{
    if (P->rear == -1)
        return (1);
    return (0);
}
int full(dequeue *P)
{
    if ((P->rear + 1) % MAX == P->front)
        return (1);
    return (0);
}
void insert_right(dequeue *P, int x)
{
    if (empty(P))
    {
        P->rear = 0;
        P->front = 0;
        P->data[0] = x;
    }
    else
    {
        P->rear = (P->rear + 1) % MAX;
        P->data[P->rear] = x;
    }
}

int delete_left(dequeue *P)
{
    int x;
    x = P->data[P->front];
    if (P->rear == P->front) 
        initialize(P);
    else
        P->front = (P->front + 1) % MAX;
    return (x);
}
int delete_right(dequeue *P)
{
    int x;
    x = P->data[P->rear];
    if (P->rear == P->front)
        initialize(P);
    else
        P->rear = (P->rear - 1 + MAX) % MAX;
    return (x);
}
void print(dequeue *P)
{
    if (empty(P))
    {
        printf("\nQueue is empty!!");
        exit(0);
    }
    int i;
    i = P->front;
    while (i != P->rear)
    {
        printf("%d  ", P->data[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", P->data[P->rear]);
}
void main()
{
    int i, x, op, n;
    dequeue q;
    initialize(&q);
    do
    {
        printf("\n1.Create\n2.Insert(right)\n3.Delete(right)");
        printf("\n4.Delete(left)\n5.Print\n6.Exit\nEnter your choice:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter number of elements:");
            scanf("%d", &n);
            initialize(&q);
            printf("\nEnter the data:");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &x);
                if (full(&q))
                {
                    printf("\nQueue is full!!");
                    exit(0);
                }
                insert_right(&q, x);
            }
            break;
        case 2:
            printf("\nEnter element to be inserted:");
            scanf("%d", &x);
            if (full(&q))
            {
                printf("\nQueue is full!!");
                exit(0);
            }
            insert_right(&q, x);
            break;
        
        case 3:
            if (empty(&q))
            {
                printf("\nQueue is empty!!");
                exit(0);
            }
            x = delete_right(&q);
            printf("\nElement deleted is %d\n", x);
            break;
        case 4:
            if (empty(&q))
            {
                printf("\nQueue is empty!!");
                exit(0);
            }
            x = delete_left(&q);
            printf("\nElement deleted is %d\n", x);
            break;
        case 5:
            print(&q);
            break;
        default:
            break;
        }
    } while (op != 6);
   
}
