/*
At the time of the council, let the council team prepare the master Database of School of Computer Engineering students 
through the linked list. At the time of maintaining the database let the council team stores the CSE student information 
at the beginning of the linked list and the IT student information at the end of the linked list. When the council team 
handover the student database to the School, let it partition the master linked list into two linked lists (CSE & IT) by 
breaking the list into two parts as per the branch. Write a Program to implement this. 
Student Information: 
a.	Name (String)
b.	Father’s Name (String)
c.	Phone Number (10 digit int array)
d.	Location (String)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct database
{
    char name[50];
    char ft_name[50];
    char phn[20];
    char location[100];
    char dept;
    struct database *next;
};
struct database *head, *temp, *newnode;
struct database *head_C = NULL, *head_I = NULL;
void insert_from_first()
{
    head = NULL;
    int ch = 1;
    printf("Enter data of students from Beginning : \n");
    while (ch)
    {
        newnode = (struct database *)malloc(sizeof(struct database));
        printf("Enter Department : ");
        scanf("%c", &newnode->dept);
        getchar();
        printf("Enter name : ");
        gets(newnode->name);
        printf("Enter father's name : ");
        gets(newnode->ft_name);
        printf("Enter phone number : ");
        gets(newnode->phn);
        printf("Enter location : ");
        gets(newnode->location);
        newnode->next = NULL;
        if (head == NULL)
            head = temp = newnode;
        else
        {
            temp = head;
            head = newnode;
            head->next = temp;
            temp = temp->next;
        }
        printf("Do you want to continue ?? 1 for Yes 0 for No : ");
        scanf("%d", &ch);
        getchar();
    }
}
void insert_from_last()
{
    int ch = 1;
    temp = head;
    while (temp->next != 0)
        temp = temp->next;
    printf("Enter data of students from Last : \n");
    while (ch)
    {
        newnode = (struct database *)malloc(sizeof(struct database));
        printf("Enter Department : ");
        scanf("%c", &newnode->dept);
        getchar();
        printf("Enter name : ");
        gets(newnode->name);
        printf("Enter father's name : ");
        gets(newnode->ft_name);
        printf("Enter phone number : ");
        gets(newnode->phn);
        printf("Enter location : ");
        gets(newnode->location);
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
        temp = newnode;
        printf("Do you want to continue ?? 1 for Yes 0 for No : ");
        scanf("%d", &ch);
        getchar();
    }
}
struct database *seg_until_create(char *name, char *ftname, char *loc, char *phn, char dp)
{
    struct database *new = (struct database *)malloc(sizeof(struct database));
    strcpy(new->name, name);
    strcpy(new->ft_name, ftname);
    strcpy(new->location, loc);
    strcpy(new->phn, phn);
    new->dept = dp;
    new->next = NULL;
    return new;
}
struct database *seg_until_insert(struct database *head, char *name, char *ftname, char *loc, char *phn, char dp)
{
    struct database *x_n = seg_until_create(name, ftname, loc, phn, dp);
    if (head == NULL)
        return x_n;
    else
    {
        struct database *t_new = head;
        while (t_new->next != NULL)
            t_new = t_new->next;
        t_new->next = x_n;
        return head;
    }
}
void seggregate(struct database *head)
{
    struct database *temp = head;
    struct database *del_n;
    while (temp != NULL)
    {
        if (temp->dept == 'C'||temp->dept == 'c')
            head_C = seg_until_insert(head_C, temp->name, temp->ft_name, temp->location, temp->phn, temp->dept);
        else
            head_I = seg_until_insert(head_I, temp->name, temp->ft_name, temp->location, temp->phn, temp->dept);
        del_n = temp;
        temp = temp->next;
        free(del_n);
    }
}
void traverse_print(struct database *head)
{
    if (head == NULL)
        printf("No student in a department ! \n");
    else
    {
        while (head != NULL)
        {
            printf("%s\t%s\t%s\t%s\t%c\n", head->name, head->ft_name, head->location, head->phn, head->dept);
            head = head->next;
        }
    }
    printf("\n");
}
int main()
{
    insert_from_first();
    insert_from_last();
    printf("\n------ALL DETAILS------\n");
     printf("NAME\tFATHER\tADDRESS\tPHONE\tDEPARTMENT\n");
    traverse_print(head);
    seggregate(head);
    printf("\n----------CSE----------\n");
    printf("NAME\tFATHER\tADDRESS\tPHONE\tDEPARTMENT\n");
    traverse_print(head_C);
    printf("\n----------IT----------\n");
    printf("NAME\tFATHER\tADDRESS\tPHONE\tDEPARTMENT\n");
    traverse_print(head_I);
    return 0;
}