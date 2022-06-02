/*20051001_Lab-2_Q1
    Write a program to remove repeated elements in a given array. 
*/
#include <stdio.h>
#include<stdlib.h>
int remove_duplicate (int arr_1001[], int n_1001) 
{
    if (n_1001 == 0 || n_1001 == 1)
        return n_1001;
    int temp_1001[n_1001];
    int j_1001 = 0;
    int i_1001;
    for (i_1001 = 0; i_1001 < n_1001 - 1; i_1001++)
    {
       if (arr_1001[i_1001] != arr_1001[i_1001 + 1])
        temp_1001[j_1001++] = arr_1001[i_1001];
    } 
    temp_1001[j_1001++] = arr_1001[n_1001 - 1];
    for (i_1001 = 0; i_1001 < j_1001; i_1001++)
    arr_1001[i_1001] = temp_1001[i_1001];
    return j_1001;
}
 
int main () 
{
    int n_1001;
    printf("enter size of array : ");
    scanf ("%d", &n_1001);
    int arr_1001[n_1001];
    int i_1001, temp_1001;
    printf("enter elements of the array :\n");
    for (i_1001 = 0; i_1001 < n_1001; i_1001++)
        {
        scanf ("%d", &arr_1001[i_1001]);
        }
    printf ("\nArray Before Removing Duplicates: ");
   
 for (i_1001 = 0; i_1001 < n_1001; i_1001++)
        printf ("%d ", arr_1001[i_1001]);
     for(int i_1001=0;i_1001<n_1001-1;i_1001++)
    {
        for(int j_1001=i_1001+1;j_1001<n_1001;j_1001++){
            if(arr_1001[j_1001]<arr_1001[i_1001])
            {
                int temp_1001=arr_1001[j_1001];
                arr_1001[j_1001]=arr_1001[i_1001];
                arr_1001[i_1001]=temp_1001;
            }
        }
    }   
    n_1001 = remove_duplicate (arr_1001, n_1001);
    printf ("\nArray After Removing Duplicates: ");
    for (i_1001 = 0; i_1001 < n_1001; i_1001++)
        printf ("%d ", arr_1001[i_1001]);
    return 0;

}