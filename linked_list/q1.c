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
    char name_1001[50];
    char ft_name_1001[50];
    char phn_1001[20];
    char location_1001[100];
    char dept_1001;
    struct database *next_1001;
};
struct database *head_1001, *temp_1001, *newnode_1001;
struct database *head_C_1001 = NULL, *head_I_1001 = NULL;
void insert_from_first()
{
    head_1001 = NULL;
    int ch_1001 = 1;
    printf("Enter data of students from Beginning : \n");
    while (ch_1001)
    {
        newnode_1001 = (struct database *)malloc(sizeof(struct database));
        printf("Enter Department : ");
        scanf("%c", &newnode_1001->dept_1001);
        getchar();
        printf("Enter name : ");
        gets(newnode_1001->name_1001);
        printf("Enter father's name : ");
        gets(newnode_1001->ft_name_1001);
        printf("Enter phone number : ");
        gets(newnode_1001->phn_1001);
        printf("Enter location : ");
        gets(newnode_1001->location_1001);
        newnode_1001->next_1001 = NULL;
        if (head_1001 == NULL)
            head_1001 = temp_1001 = newnode_1001;
        else
        {
            temp_1001 = head_1001;
            head_1001 = newnode_1001;
            head_1001->next_1001 = temp_1001;
            temp_1001 = temp_1001->next_1001;
        }
        printf("Do you want to continue ?? 1 for Yes 0 for No : ");
        scanf("%d", &ch_1001);
        getchar();
    }
}
void insert_from_last()
{
    int ch_1001 = 1;
    temp_1001 = head_1001;
    while (temp_1001->next_1001 != 0)
        temp_1001 = temp_1001->next_1001;
    printf("Enter data of students from Last : \n");
    while (ch_1001)
    {
        newnode_1001 = (struct database *)malloc(sizeof(struct database));
        printf("Enter Department : ");
        scanf("%c", &newnode_1001->dept_1001);
        getchar();
        printf("Enter name : ");
        gets(newnode_1001->name_1001);
        printf("Enter father's name : ");
        gets(newnode_1001->ft_name_1001);
        printf("Enter phone number : ");
        gets(newnode_1001->phn_1001);
        printf("Enter location : ");
        gets(newnode_1001->location_1001);
        newnode_1001->next_1001 = NULL;
        temp_1001->next_1001 = newnode_1001;
        temp_1001 = temp_1001->next_1001;
        temp_1001 = newnode_1001;
        printf("Do you want to continue ?? 1 for Yes 0 for No : ");
        scanf("%d", &ch_1001);
        getchar();
    }
}
struct database *seg_until_create(char *name_1001, char *ftname_1001, char *loc_1001, char *phn_1001, char dp_1001)
{
    struct database *new_1001 = (struct database *)malloc(sizeof(struct database));
    strcpy(new_1001->name_1001, name_1001);
    strcpy(new_1001->ft_name_1001, ftname_1001);
    strcpy(new_1001->location_1001, loc_1001);
    strcpy(new_1001->phn_1001, phn_1001);
    new_1001->dept_1001 = dp_1001;
    new_1001->next_1001 = NULL;
    return new_1001;
}
struct database *seg_until_insert(struct database *head_1001, char *name_1001, char *ftname_1001, char *loc_1001, char *phn_1001, char dp_1001)
{
    struct database *x_n_1001 = seg_until_create(name_1001, ftname_1001, loc_1001, phn_1001, dp_1001);
    if (head_1001 == NULL)
        return x_n_1001;
    else
    {
        struct database *t_new_1001 = head_1001;
        while (t_new_1001->next_1001 != NULL)
            t_new_1001 = t_new_1001->next_1001;
        t_new_1001->next_1001 = x_n_1001;
        return head_1001;
    }
}
void seggregate(struct database *head_1001)
{
    struct database *temp_1001 = head_1001;
    struct database *del_n_1001;
    while (temp_1001 != NULL)
    {
        if (temp_1001->dept_1001 == 'C'||temp_1001->dept_1001 == 'c')
            head_C_1001 = seg_until_insert(head_C_1001, temp_1001->name_1001, temp_1001->ft_name_1001, temp_1001->location_1001, temp_1001->phn_1001, temp_1001->dept_1001);
        else
            head_I_1001 = seg_until_insert(head_I_1001, temp_1001->name_1001, temp_1001->ft_name_1001, temp_1001->location_1001, temp_1001->phn_1001, temp_1001->dept_1001);
        del_n_1001 = temp_1001;
        temp_1001 = temp_1001->next_1001;
        free(del_n_1001);
    }
}
void traverse_print(struct database *head_1001)
{
    if (head_1001 == NULL)
        printf("No student in a department ! \n");
    else
    {
        while (head_1001 != NULL)
        {
            printf("%s\t%s\t%s\t%s\t%c\n", head_1001->name_1001, head_1001->ft_name_1001, head_1001->location_1001, head_1001->phn_1001, head_1001->dept_1001);
            head_1001 = head_1001->next_1001;
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
    traverse_print(head_1001);
    seggregate(head_1001);
    printf("\n----------CSE----------\n");
    printf("NAME\tFATHER\tADDRESS\tPHONE\tDEPARTMENT\n");
    traverse_print(head_C_1001);
    printf("\n----------IT----------\n");
    printf("NAME\tFATHER\tADDRESS\tPHONE\tDEPARTMENT\n");
    traverse_print(head_I_1001);
    return 0;
}