#include <stdio.h>
#include <stdlib.h>
void linearsearch(int a[],int n)
{
    int item,i;
     printf("\n enter the item to be searched : ");
        scanf("%d", &item);
        for (i = 0; i < n; i++)
        {
            if (a[i] == item)
            {
                printf("\n item found at position : %d", i + 1);
                break;
            }
        }
        if (i == n)
            printf("\n item not found");
}
void binarysearch(int a[],int n)
{
    int item,last,mid,beg;
      printf("Enter item to be searched : ");
        scanf("%d", &item);
        last = n - 1;
        mid = (beg + last) / 2;
        while (beg <= last)
        {
            if (item == a[mid])
            {
                printf("\n item found at position : %d", mid + 1);
                break;
            }
            else if (a[mid] > item)
                last = mid - 1;
            else
                beg = mid + 1;
            mid = (beg + last) / 2;
        }
}
int main()
{
    int n,ch;
    printf("enter the size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("enter array element in sorted order: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n 1.linear search");
    printf("\n 2.binary search");
    printf("\n enter the choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
        case 1:
            printf("implementing linear search....\n");
            linearsearch(a,n);
        break;
        case 2:
            printf("implementing binary search....\n");
            binarysearch(a,n);
        break;
    }
}