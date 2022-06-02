/*
1) WAP to find the smallest & largest number in the array
*/
#include <stdio.h>
int main()
{   int n;
    printf("enter number of elements in an array: \n");
    scanf("%d",&n);
    int arr[n] ;
    int minn, maxx;
    printf("enter %d no of elements : \n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    maxx = arr[0], minn = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxx){
            maxx = arr[i];
        }
        else if (arr[i] < minn) 
{
            minn = arr[i];
        }
    }
    printf("The minimum array element is %d\n", minn);
    printf("The maximum array element is %d\n",maxx);
    return 0;
}