/*
In a one dimensional array, user gives a certain range of index with shifting value.
You need to right shift and rotate those range of values based on the given shifting
value.
Given array: 2,9,6,3,5,8,11,3,6,7,13,5 
Given range: 4th index to 9th index(consider the starting index is 0) and shifting value is 2 
Output: 2,9,6,3,6,7,5,8,11,3,13,5 

*/
#include <stdio.h>
#include<stdlib.h>

void rightrotate(int arr[], int j, int k)
{
    int last = arr[k];
    for (int i = k - 1; i>= j; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[j] = last;
}
void nrotates(int arr[], int s, int j, int k)
{
    for (int i = 0; i < s; i++)
    {
        rightrotate(arr, j, k);
    }
}
int main()
{
    int n;
    printf("Enter Size Of Array : ");
    scanf("%d",&n) ;
    printf("Enter The Elements Of Array :") ;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
       scanf("%d",&arr[i]);
    }
    printf("Enter the range : ");
    int j, k;
    scanf("%d%d",&j,&k);
    printf("Enter the no of shifts : ");
    int s;
    scanf("%d",&s);
    nrotates(arr, s, j, k);
    printf( "Array After Rotations  : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}