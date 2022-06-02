/*
2.Let in one conference, at the time of registration process the registration desk prepare one master linked list
to register the participant irrespective of their type.Let the type of participants are Student, Guest, Organizing team,
Delegate.Implement this using a single linked list where each participant information are as follows : 
  a.Name(String) 
  b.Type of Participant(Char : For Student - ‘S’, Guest - ’G’, Organizing team - ‘O’, Delegate - ‘D’) 
  c.Phone number(10 digit int array) 
After maintaining the master linked list let the master list will be segregated into 4 linked lists as per 
the type of participant.[Note:Delete from the master linked list and insert in the appropriate participant list.]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char name[50];
    char type;
    char mob[15];
    struct node *next;
};
struct node *newnode;
struct node *head, *temp;
struct node *headS = NULL;
struct node *headG = NULL;
struct node *headO = NULL;
struct node *headD = NULL;

void create()
{
    int ch = 1;
    head = NULL;
    while (ch)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for Participants : \n");
        printf("Enter participant type : ");
        scanf("%c", &newnode->type);
        getchar();
        printf("Enter name : ");
        gets(newnode->name);
        printf("Enter Phone number : ");
        gets(newnode->mob);
        newnode->next = NULL;
        if (head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
        printf("Do you want to continue ? 1 for Yes : 0 for No :: ");
        scanf("%d", &ch);
        getchar();
    }
}
struct node *seg_until_create(char *name, char type, char *mob)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    strcpy(n->name, name);
    n->type = type;
    strcpy(n->mob, mob);
    n->next = NULL;
    return n;
}
struct node *seg_until_ins(struct node *head, char *name, char type, char *mob)
{
    struct node *x = seg_until_create(name, type, mob);
    if (head == NULL)
        return x;
    else
    {
        struct node *c = head;
        while (c->next != NULL)
            c = c->next;
        c->next = x;
        return head;
    }
}
void segregate(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->type == 'S')
            headS = seg_until_ins(headS, temp->name, temp->type, temp->mob);
        if (temp->type == 'G')
            headG = seg_until_ins(headG, temp->name, temp->type, temp->mob);
        if (temp->type == 'O')
            headO = seg_until_ins(headO, temp->name, temp->type, temp->mob);
        else if (temp->type == 'D')
            headD = seg_until_ins(headD, temp->name, temp->type, temp->mob);
        struct node *toBeDel = temp;
        temp = temp->next;
        free(toBeDel);
    }
}
void traverse(struct node *head)
{
    if (head == NULL)
        printf("Empty List !\n");

    while (head != NULL)
    {
        printf("%s\t%c\t%s\n", head->name, head->type, head->mob);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    create();
    printf("--------ALL DETAILS--------\n");
    printf("NAME\tTYPE\tPHONE\n");
    traverse(head);
    segregate(head);
    printf("--------STUDENTS--------\n");
    printf("NAME\tTYPE\tPHONE\n");
    traverse(headS);
    printf("--------GUEST--------\n");
    printf("NAME\tTYPE\tPHONE\n");
    traverse(headG);
    printf("--------ORGANIZING TEAM--------\n");
    printf("NAME\tTYPE\tPHONE\n");
    traverse(headO);
    printf("--------DELEGATE--------\n");
    printf("NAME\tTYPE\tPHONE\n");
    traverse(headD);
    return 0;
}
