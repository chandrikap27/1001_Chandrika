#include <stdio.h>
#include <stdlib.h>
struct patient
{
    char gender_1001, name_1001[10], disease_1001[10];
    struct patient *link_1001;
} *wmh_1001 = NULL, *wmt_1001 = NULL, *wfh_1001 = NULL, *wft_1001 = NULL;
struct cabin
{
    int no_1001;
    char status_1001;
    struct patient *pat_1001;
    struct cabin *link_1001;
} *master_1001 = NULL, *temp_1001;
int countm_1001 = 0, countf_1001 = 0, n_1001, mmax_1001, fmax_1001;
void create()
{   
    for (int i_1001 = 0; i_1001 < n_1001; i_1001++)
    {
        struct cabin *new_1001 = (struct cabin*)malloc(sizeof(struct cabin));
        new_1001->no_1001 = i_1001+1;
        new_1001->status_1001 = 'N';
        new_1001->link_1001 = NULL;
        new_1001->pat_1001 = NULL;
        if (master_1001==NULL) 
        {
            master_1001 = new_1001;
            temp_1001 = new_1001;
        }
        else
        {
            temp_1001->link_1001 = new_1001;
            temp_1001 = new_1001;
        }
    }
}
void admit()
{
    struct patient *new_1001 = (struct patient*)malloc(sizeof(struct patient));
    printf("Enter Name : ");
    fflush(stdin);
    scanf("%s", new_1001->name_1001);
    fflush(stdin);
    printf("Enter Gender : ");
    scanf("%c", &(new_1001->gender_1001));
    fflush(stdin);
    printf("Enter disease : ");
    scanf("%s", new_1001->disease_1001);
    new_1001->link_1001 = NULL;
    struct cabin *temp_1001;
    if (new_1001->gender_1001 == 'M'||new_1001->gender_1001=='m')
    {
        if (countm_1001 < mmax_1001)
        {
            countm_1001++;
            temp_1001 = master_1001;
            while (temp_1001)
            {
                if (temp_1001->status_1001 == 'N')
                {
                    temp_1001->pat_1001 = new_1001;
                    temp_1001->status_1001 = 'Y';
                    break;
                }
                if (temp_1001->link_1001)
                    temp_1001 = temp_1001->link_1001->link_1001;
                else
                    break;
            }
        }
        else
        {
            if (!wmh_1001)
            {
                wmh_1001 = new_1001;
                wmt_1001 = new_1001;
            }
            else
            {
                wmt_1001->link_1001 = new_1001;
                wmt_1001 = new_1001;
            }
        }
    }
    else if (new_1001->gender_1001 == 'F'||new_1001->gender_1001 == 'f')
    {
        if (countf_1001 < fmax_1001)
        {
            countf_1001++;
            temp_1001 = master_1001->link_1001;
            while (temp_1001)
            {
                if (temp_1001->status_1001 == 'N')
                {
                    temp_1001->pat_1001 = new_1001;
                    temp_1001->status_1001 = 'Y';
                    break;
                }
                if (temp_1001->link_1001)
                    temp_1001 = temp_1001->link_1001->link_1001;
                else
                    break;
            }
        }
        else
        {
            if (!wfh_1001)
            {
                wfh_1001 = new_1001;
                wft_1001 = new_1001;
            }
            else
            {
                wft_1001->link_1001 = new_1001;
                wft_1001 = new_1001;
            }
        }
    }
}
void discharge()
{
    int in_1001;
    temp_1001 = master_1001;
in:
    printf("Enter cabin no. : ");
    scanf("%d", &in_1001);
    if (in_1001 > n_1001 || in_1001 < 1)
    {
        printf("Invalid input : ");
        goto in;
    }
    while (temp_1001)
    {
        if (temp_1001->no_1001 == in_1001)
        {
            if (in_1001 % 2)
            {
                if (wmh_1001)
                {
                    temp_1001->pat_1001 = wmh_1001;
                    wmh_1001 = wmh_1001->link_1001;
                }
                else
                    temp_1001->status_1001 = 'N';
            }
            else
            {
                if (wfh_1001)
                {
                    temp_1001->pat_1001 = wfh_1001;
                    wfh_1001 = wfh_1001->link_1001;
                }
                else
                    temp_1001->status_1001 = 'N';
            }
            temp_1001->pat_1001->link_1001 = NULL;
            break;
        }
        temp_1001 = temp_1001->link_1001;
    }
}
void display()
{
    temp_1001 = master_1001;
    while (temp_1001)
    {
        if (temp_1001->status_1001 == 'Y')
        {
            printf("Cabin No. : %d\n", temp_1001->no_1001);
            printf("Name : %s\n", temp_1001->pat_1001->name_1001);
            printf("Gender : %c\n", temp_1001->pat_1001->gender_1001);
            printf("Disease : %s\n", temp_1001->pat_1001->disease_1001);
            printf("\n");
        }
        temp_1001 = temp_1001->link_1001;
    }
    struct patient *pat_1001 = malloc(sizeof(struct patient));
    if (!wmh_1001)
        printf("Waiting List for Male is Empty\n");
    else
    {   
        printf("----WAITING LIST MALE ----- \n");
        pat_1001 = wmh_1001;
        while (pat_1001)
        {
            printf("Name : %s\n", pat_1001->name_1001);
            printf("Gender : %c\n", pat_1001->gender_1001);
            printf("Disease : %s\n", pat_1001->disease_1001);
            printf("\n");
            pat_1001 = pat_1001->link_1001;
        }
    }
    if (!wfh_1001)
        printf("Waiting List for Female is Empty\n");
    else
    {
        printf("----WAITING LIST FEMALE----\n");
        pat_1001 = wfh_1001;
        while (pat_1001)
        {
            printf("Name : %s\n", pat_1001->name_1001);
            printf("Gender : %c\n", pat_1001->gender_1001);
            printf("Disease : %s\n", pat_1001->disease_1001);
            printf("\n");
            pat_1001 = pat_1001->link_1001;
        }
    }
}
int main()
{
    int ch_1001;
in:
    printf("Enter the value of n : ");
    scanf("%d", &n_1001);
    if (n_1001 < 1)
    {
        printf("Invalid Input\n");
        goto in;
    }
    mmax_1001 = n_1001 / 2 + n_1001 % 2, fmax_1001 = n_1001 / 2;
    create();
    printf("\nEnter 1. to admit");
    printf("\nEnter 2. to discharge");
    printf("\nEnter 3. to display");
    printf("\nEnter 0. to exit");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch_1001);
        if (ch_1001 == 1)
            admit();
        else if (ch_1001 == 2)
            discharge();
        else if (ch_1001 == 3)
            display();
        else if (ch_1001 == 0)
            break;
        else
            printf("Wrong Input\n");
    }
    return 0;
}