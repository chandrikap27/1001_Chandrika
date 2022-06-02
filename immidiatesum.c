/* 20051001_Lab-1_Q7
7. In a one dimensional array find out all the elements and their position, which is the
summation of its immediate previous contiguous elements.
Ex: Given array: 2,9,6,3,9,8,17,3,6,4,13,5
Output: output is 9, which is a summation of it’s previous elements 3 and 6
output is 13, which is a summation of it’s previous elements 4,6 and 3
*/
#include <stdio.h>

int main() {
    int n_1001;
    printf("Enter the size of array : ");
    scanf("%d",&n_1001);
    int arr_1001[n_1001];
    printf("\nenter the elements of the array: ");
    for(int i_1001=0;i_1001<n_1001;i_1001++) {
        scanf("%d",&arr_1001[i_1001]);
    }
    
    printf("all the elements , which is the summation of its immediate previous contiguous elements.  is : ");
    for(int i_1001=0;i_1001<n_1001;i_1001++) {
        int sum_1001=arr_1001[i_1001];
        for(int j_1001=i_1001+1;j_1001<=n_1001;j_1001++) {
            sum_1001+=arr_1001[j_1001];
            if(sum_1001==arr_1001[j_1001+1]) {
            printf("%d  ",arr_1001[j_1001+1]);
            break;
            }
        }
    }
    
    return 0;   
}