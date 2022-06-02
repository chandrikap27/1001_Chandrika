#include <stdio.h>
#include <stdlib.h>
struct patient
{
    char gender, name[10], disease[10];
    struct patient *link;
} *wmh = NULL, *wmt = NULL, *wfh = NULL, *wft = NULL;
struct cabin
{
    int no;
    char status;
    struct patient *pat;
    struct cabin *link;
} *master = NULL, *temp;
int countm = 0, countf = 0, n, mmax, fmax;
void create()
{   
    for (int i = 0; i < n; i++)
    {
        struct cabin *new = (struct cabin*)malloc(sizeof(struct cabin));
        new->no = i+1;
        new->status = 'N';
        new->link = NULL;
        new->pat = NULL;
        if (master==NULL) 
        {
            master = new;
            temp = new;
        }
        else
        {
            temp->link = new;
            temp = new;
        }
    }
}
void admit()
{
    struct patient *new = (struct patient*)malloc(sizeof(struct patient));
    printf("Enter Name : ");
    fflush(stdin);
    scanf("%s", new->name);
    fflush(stdin);
    printf("Enter Gender : ");
    scanf("%c", &(new->gender));
    fflush(stdin);
    printf("Enter disease : ");
    scanf("%s", new->disease);
    new->link = NULL;
    struct cabin *temp;
    if (new->gender == 'M'||new->gender=='m')
    {
        if (countm < mmax)
        {
            countm++;
            temp = master;
            while (temp)
            {
                if (temp->status == 'N')
                {
                    temp->pat = new;
                    temp->status = 'Y';
                    break;
                }
                if (temp->link)
                    temp = temp->link->link;
                else
                    break;
            }
        }
        else
        {
            if (!wmh)
            {
                wmh = new;
                wmt = new;
            }
            else
            {
                wmt->link = new;
                wmt = new;
            }
        }
    }
    else if (new->gender == 'F'||new->gender == 'f')
    {
        if (countf < fmax)
        {
            countf++;
            temp = master->link;
            while (temp)
            {
                if (temp->status == 'N')
                {
                    temp->pat = new;
                    temp->status = 'Y';
                    break;
                }
                if (temp->link)
                    temp = temp->link->link;
                else
                    break;
            }
        }
        else
        {
            if (!wfh)
            {
                wfh = new;
                wft = new;
            }
            else
            {
                wft->link = new;
                wft = new;
            }
        }
    }
}
void discharge()
{
    int in;
    temp = master;
in:
    printf("Enter cabin no. : ");
    scanf("%d", &in);
    if (in > n || in < 1)
    {
        printf("Invalid input : ");
        goto in;
    }
    while (temp)
    {
        if (temp->no == in)
        {
            if (in % 2)
            {
                if (wmh)
                {
                    temp->pat = wmh;
                    wmh = wmh->link;
                }
                else
                    temp->status = 'N';
            }
            else
            {
                if (wfh)
                {
                    temp->pat = wfh;
                    wfh = wfh->link;
                }
                else
                    temp->status = 'N';
            }
            temp->pat->link = NULL;
            break;
        }
        temp = temp->link;
    }
}
void display()
{
    temp = master;
    while (temp)
    {
        if (temp->status == 'Y')
        {
            printf("Cabin No. : %d\n", temp->no);
            printf("Name : %s\n", temp->pat->name);
            printf("Gender : %c\n", temp->pat->gender);
            printf("Disease : %s\n", temp->pat->disease);
            printf("\n");
        }
        temp = temp->link;
    }
    struct patient *pat = malloc(sizeof(struct patient));
    if (!wmh)
        printf("Waiting List for Male is Empty\n");
    else
    {   
        printf("----WAITING LIST MALE ----- \n");
        pat = wmh;
        while (pat)
        {
            printf("Name : %s\n", pat->name);
            printf("Gender : %c\n", pat->gender);
            printf("Disease : %s\n", pat->disease);
            printf("\n");
            pat = pat->link;
        }
    }
    if (!wfh)
        printf("Waiting List for Female is Empty\n");
    else
    {
        printf("----WAITING LIST FEMALE----\n");
        pat = wfh;
        while (pat)
        {
            printf("Name : %s\n", pat->name);
            printf("Gender : %c\n", pat->gender);
            printf("Disease : %s\n", pat->disease);
            printf("\n");
            pat = pat->link;
        }
    }
}
int main()
{
    int ch;
in:
    printf("Enter the value of n : ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Invalid Input\n");
        goto in;
    }
    mmax = n / 2 + n % 2, fmax = n / 2;
    create();
    printf("\nEnter 1. to admit");
    printf("\nEnter 2. to discharge");
    printf("\nEnter 3. to display");
    printf("\nEnter 0. to exit");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        if (ch == 1)
            admit();
        else if (ch == 2)
            discharge();
        else if (ch == 3)
            display();
        else if (ch == 0)
            break;
        else
            printf("Wrong Input\n");
    }
    return 0;
}