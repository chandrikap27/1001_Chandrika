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
    char name_1001[50];
    char type_1001;
    char mob_1001[15];
    struct node *next_1001;
};
struct node *newnode_1001;
struct node *head_1001, *temp_1001;
struct node *headS_1001 = NULL;
struct node *headG_1001 = NULL;
struct node *headO_1001 = NULL;
struct node *headD_1001 = NULL;

void create()
{
    int ch_1001 = 1;
    head_1001 = NULL;
    while (ch_1001)
    {
        newnode_1001 = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for Participants : \n");
        printf("Enter participant type : ");
        scanf("%c", &newnode_1001->type_1001);
        getchar();
        printf("Enter name : ");
        gets(newnode_1001->name_1001);
        printf("Enter Phone number : ");
        gets(newnode_1001->mob_1001);
        newnode_1001->next_1001 = NULL;
        if (head_1001 == NULL)
            head_1001 = temp_1001 = newnode_1001;
        else
        {
            temp_1001->next_1001 = newnode_1001;
            temp_1001 = temp_1001->next_1001;
        }
        printf("Do you want to continue ? 1 for Yes : 0 for No :: ");
        scanf("%d", &ch_1001);
        getchar();
    }
}
struct node *seg_until_create(char *name_1001, char type_1001, char *mob_1001)
{
    struct node *n_1001 = (struct node *)malloc(sizeof(struct node));
    strcpy(n_1001->name_1001, name_1001);
    n_1001->type_1001 = type_1001;
    strcpy(n_1001->mob_1001, mob_1001);
    n_1001->next_1001 = NULL;
    return n_1001;
}
struct node *seg_until_ins(struct node *head_1001, char *name_1001, char type_1001, char *mob_1001)
{
    struct node *x_1001 = seg_until_create(name_1001, type_1001, mob_1001);
    if (head_1001 == NULL)
        return x_1001;
    else
    {
        struct node *c_1001 = head_1001;
        while (c_1001->next_1001 != NULL)
            c_1001 = c_1001->next_1001;
        c_1001->next_1001 = x_1001;
        return head_1001;
    }
}
void segregate(struct node *head_1001)
{
    struct node *temp_1001 = head_1001;
    while (temp_1001 != NULL)
    {
        if (temp_1001->type_1001 == 'S')
            headS_1001 = seg_until_ins(headS_1001, temp_1001->name_1001, temp_1001->type_1001, temp_1001->mob_1001);
        if (temp_1001->type_1001 == 'G')
            headG_1001 = seg_until_ins(headG_1001, temp_1001->name_1001, temp_1001->type_1001, temp_1001->mob_1001);
        if (temp_1001->type_1001 == 'O')
            headO_1001 = seg_until_ins(headO_1001, temp_1001->name_1001, temp_1001->type_1001, temp_1001->mob_1001);
        else if (temp_1001->type_1001 == 'D')
            headD_1001 = seg_until_ins(headD_1001, temp_1001->name_1001, temp_1001->type_1001, temp_1001->mob_1001);
        struct node *toBeDel_1001 = temp_1001;
        temp_1001 = temp_1001->next_1001;
        free(toBeDel_1001);
    }
}
void traverse(struct node *head_1001)
{
    if (head_1001 == NULL)
        printf("Empty List !\n");

    while (head_1001 != NULL)
    {
        printf("%s\t%c\t%s\n", head_1001->name_1001, head_1001->type_1001, head_1001->mob_1001);
        head_1001 = head_1001->next_1001;
    }
    printf("\n");
}

int main()
{
    create();
    printf("--------ALL DETAILS--------\n");
    printf("NAME\tTYPE\tPHONE\n");
    traverse(head_1001);
    segregate(head_1001);
    printf("--------STUDENTS--------\n");
    printf("NAME\tTYPE\tPHONE\n");
    traverse(headS_1001);
    printf("--------GUEST--------\n");
    printf("NAME\tTYPE\tPHONE\n");
    traverse(headG_1001);
    printf("--------ORGANIZING TEAM--------\n");
    printf("NAME\tTYPE\tPHONE\n");
    traverse(headO_1001);
    printf("--------DELEGATE--------\n");
    printf("NAME\tTYPE\tPHONE\n");
    traverse(headD_1001);
    return 0;
}
