/* 20051001_Lab-2_Q2
    1)Write a program to find the maximum number of consecutive elements present in
     ascending order
*/
#include <stdio.h>

int main()
{
    int  n_1001, s_1001 = 0, l_1001 = 0, start_1001;
    printf("Enter size of array: ");
    scanf("%d",&n_1001);
    int arr_1001[n_1001];
    printf("Enter Elements: ");
    for (int i_1001 = 0; i_1001 < n_1001; i_1001++)
    {
         scanf("%d",&arr_1001[i_1001]);
    }
     printf("\nAll the consecutive elements sets: \n");
    for (int i_1001 = 0; i_1001 < n_1001 - 1; i_1001++)
    {
        printf("\n");
        int f_1001 = i_1001;
        int c_1001 = 0;
        while (arr_1001[f_1001 + 1] > arr_1001[f_1001])
        {
            printf("%d ",arr_1001[f_1001]);
            f_1001++;
            c_1001++;
            if (f_1001 >= n_1001 - 1)
                break;
        }
        c_1001++;
        if (c_1001 > 1)
        {
            printf("%d ",arr_1001[f_1001]);
            s_1001++;
        }
        if (c_1001 > l_1001)
        {
            l_1001 = c_1001;
            start_1001 = i_1001;
        }
        i_1001 = f_1001;
    }
    printf("\nNumber of sets : %d\n",s_1001);
    printf("Set with maximum no. of elements: ");
    for (int i_1001 = 0; i_1001 < l_1001; i_1001++)
    {
        printf("%d ",arr_1001[start_1001 + i_1001]);
    }
    return 0;
}