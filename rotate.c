/*20051001_Lab2_Q3
In a one dimensional array, user gives a certain range of index with shifting value.
You need to right shift and rotate those range of values based on the given shifting
value.
Given array: 2,9,6,3,5,8,11,3,6,7,13,5 
Given range: 4th index to 9th index(consider the starting index is 0) and shifting value is 2 
Output: 2,9,6,3,6,7,5,8,11,3,13,5 

*/
#include <stdio.h>
#include<stdlib.h>

void rightrotate(int arr_1001[], int j_1001, int k_1001)
{
    int last_1001 = arr_1001[k_1001];
    for (int i_1001 = k_1001 - 1; i_1001>= j_1001; i_1001--)
    {
        arr_1001[i_1001 + 1] = arr_1001[i_1001];
    }
    arr_1001[j_1001] = last_1001;
}
void nrotates(int arr_1001[], int s_1001, int j_1001, int k_1001)
{
    for (int i_1001 = 0; i_1001 < s_1001; i_1001++)
    {
        rightrotate(arr_1001, j_1001, k_1001);
    }
}
int main()
{
    int n_1001;
    printf("Enter Size Of Array : ");
    scanf("%d",&n_1001) ;
    printf("Enter The Elements Of Array :") ;
    int arr_1001[n_1001];
    for (int i_1001 = 0; i_1001 < n_1001; i_1001++)
    {
       scanf("%d",&arr_1001[i_1001]);
    }
    printf("Enter the range : ");
    int j_1001, k_1001;
    scanf("%d%d",&j_1001,&k_1001);
    printf("Enter the no of shifts : ");
    int s_1001;
    scanf("%d",&s_1001);
    nrotates(arr_1001, s_1001, j_1001, k_1001);
    printf( "Array After Rotations  : ");
    for (int i_1001 = 0; i_1001 < n_1001; i_1001++)
    {
        printf("%d ",arr_1001[i_1001]);
    }
    printf("\n");
    return 0;
}