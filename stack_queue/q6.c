
#include <stdio.h>
#include <process.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 30
typedef struct dequeue
{
    int data_1001[MAX];
    int rear_1001, front_1001;
} dequeue_1001;
void initialize(dequeue_1001 *p_1001);
int empty(dequeue_1001 *p_1001);
int full(dequeue_1001 *p_1001);
void enqueueR(dequeue_1001 *p_1001, int x_1001);
void enqueueF(dequeue_1001 *p_1001, int x_1001);
int dequeueF(dequeue_1001 *p_1001);
int dequeueR(dequeue_1001 *p_1001);
void print(dequeue_1001 *p_1001);
void main()
{
    int i_1001, x_1001, op_1001, n_1001;
    dequeue_1001 q_1001;
    initialize(&q_1001);
    do
    {
        printf("\n1.Create\n2.Insert(rear)\n3.Insert(front)\n4.Delete(rear)");
        printf("\n5.Delete(front)\n6.Print\n7.Exit\nEnter your choice:");
        scanf("%d", &op_1001);
        switch (op_1001)
        {
        case 1:
            printf("\nEnter number of elements:");
            scanf("%d", &n_1001);
            initialize(&q_1001);
            printf("\nEnter the data:");
            for (i_1001 = 0; i_1001 < n_1001; i_1001++)
            {
                scanf("%d", &x_1001);
                if (full(&q_1001))
                {
                    printf("\nQueue is full!!");
                    exit(0);
                }
                enqueueR(&q_1001, x_1001);
            }
            break;
        case 2:
            printf("\nEnter element to be inserted:");
            scanf("%d", &x_1001);
            if (full(&q_1001))
            {
                printf("\nQueue is full!!");
                exit(0);
            }
            enqueueR(&q_1001, x_1001);
            break;
        case 3:
            printf("\nEnter the element to be inserted:");
            scanf("%d", &x_1001);
            if (full(&q_1001))
            {
                printf("\nQueue is full!!");
                exit(0);
            }
            enqueueF(&q_1001, x_1001);
            break;
        case 4:
            if (empty(&q_1001))
            {
                printf("\nQueue is empty!!");
                exit(0);
            }
            x_1001 = dequeueR(&q_1001);
            printf("\nElement deleted is %d\n", x_1001);
            break;
        case 5:
            if (empty(&q_1001))
            {
                printf("\nQueue is empty!!");
                exit(0);
            }
            x_1001 = dequeueF(&q_1001);
            printf("\nElement deleted is %d\n", x_1001);
            break;
        case 6:
            print(&q_1001);
            break;
        default:
            break;
        }
    } while (op_1001 != 7);
    getch();
}
void initialize(dequeue_1001 *P_1001)
{
    P_1001->rear_1001 = -1;
    P_1001->front_1001 = -1;
}
int empty(dequeue_1001 *P_1001)
{
    if (P_1001->rear_1001 == -1)
        return (1);
    return (0);
}
int full(dequeue_1001 *P_1001)
{
    if ((P_1001->rear_1001 + 1) % MAX == P_1001->front_1001)
        return (1);
    return (0);
}
void enqueueR(dequeue_1001 *P_1001, int x_1001)
{
    if (empty(P_1001))
    {
        P_1001->rear_1001 = 0;
        P_1001->front_1001 = 0;
        P_1001->data_1001[0] = x_1001;
    }
    else
    {
        P_1001->rear_1001 = (P_1001->rear_1001 + 1) % MAX;
        P_1001->data_1001[P_1001->rear_1001] = x_1001;
    }
}
void enqueueF(dequeue_1001 *P_1001, int x_1001)
{
    if (empty(P_1001))
    {
        P_1001->rear_1001 = 0;
        P_1001->front_1001 = 0;
        P_1001->data_1001[0] = x_1001;
    }
    else
    {
        P_1001->front_1001 = (P_1001->front_1001 - 1 + MAX) % MAX;
        P_1001->data_1001[P_1001->front_1001] = x_1001;
    }
}
int dequeueF(dequeue_1001 *P_1001)
{
    int x_1001;
    x_1001 = P_1001->data_1001[P_1001->front_1001];
    if (P_1001->rear_1001 == P_1001->front_1001) 
        initialize(P_1001);
    else
        P_1001->front_1001 = (P_1001->front_1001 + 1) % MAX;
    return (x_1001);
}
int dequeueR(dequeue_1001 *P_1001)
{
    int x_1001;
    x_1001 = P_1001->data_1001[P_1001->rear_1001];
    if (P_1001->rear_1001 == P_1001->front_1001)
        initialize(P_1001);
    else
        P_1001->rear_1001 = (P_1001->rear_1001 - 1 + MAX) % MAX;
    return (x_1001);
}
void print(dequeue_1001 *P_1001)
{
    if (empty(P_1001))
    {
        printf("\nQueue is empty!!");
        exit(0);
    }
    int i_1001;
    i_1001 = P_1001->front_1001;
    while (i_1001 != P_1001->rear_1001)
    {
        printf("%d  ", P_1001->data_1001[i_1001]);
        i_1001 = (i_1001 + 1) % MAX;
    }
    printf("\n%d\n", P_1001->data_1001[P_1001->rear_1001]);
}