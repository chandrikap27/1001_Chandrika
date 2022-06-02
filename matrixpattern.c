/*20051001_Lab-2_Q4
WAP to display the following matrix in triangular form as shown in the question.
*/
#include <stdio.h>
#include <stdlib.h>
void patt_1(int **a_1001, int r_1001, int c_1001)
{
    printf("Pattern 01 : \n");
    for (int i_1001 = 0; i_1001 < r_1001; i_1001++)
    {
        for (int j_1001 = 0; j_1001 < c_1001; j_1001++)
        {
            if (j_1001 < i_1001)
                printf("%d", *(*(a_1001 + i_1001) + j_1001));
            else
                (" ");
        }
        printf("\n");
    }
    printf("\n");
}
void patt_2(int **a_1001, int r_1001, int c_1001)
{
    printf("Pattern 02 : \n");
    for (int i_1001 = 0; i_1001 < r_1001; i_1001++)
    {
        for (int j_1001 = 0; j_1001< c_1001 - i_1001; j_1001++)
            printf(" ");
        for (int x_1001 = i_1001; x_1001 > 0; x_1001--)
            printf("%d", *(*(a_1001 + i_1001) + (c_1001 - x_1001)));
        printf("\n");
    }
    printf("\n");
}
void patt_3(int **a_1001, int r_1001, int c_1001)
{
    printf("Pattern 03 : \n");
    for (int i_1001 = 0; i_1001 < r_1001 - 1; i_1001++)
    {
        for (int j_1001 = 0; j_1001 < i_1001 + 1; j_1001++)
            printf(" ");
        for (int x_1001 = i_1001 + 1; x_1001 < c_1001; x_1001++)
            printf("%d", *(*(a_1001 + i_1001) + x_1001));
        printf("\n");
    }
    printf("\n");
}
void patt_4(int **a_1001, int r_1001, int c_1001)
{
    printf("Pattern 04 : \n");
    for (int i_1001 = 0; i_1001 < r_1001; i_1001++)
    {
        for (int j_1001 = 0; j_1001 < c_1001 - i_1001 - 1; j_1001++)
            printf("%d", *(*(a_1001 + i_1001) + j_1001));
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int row_1001, col_1001;
    printf("Enter Row Number : ");
    scanf("%d", &row_1001);
    printf("Enter Column Number : ");
    scanf("%d", &col_1001);
    int **arr_1001;
    arr_1001 = (int **)malloc(row_1001 * sizeof(int *));
    if (arr_1001 == NULL)
        printf("No memory allocated : ");
    for (int i_1001 = 0; i_1001 < row_1001; i_1001++)
        arr_1001[i_1001] = (int *)malloc(col_1001 * sizeof(int));
    printf("Enter Elements of Array :\n");
    for (int i_1001 = 0; i_1001 < row_1001; i_1001++)
    {
        for (int j_1001 = 0; j_1001 < col_1001; j_1001++)
            scanf("%d", &arr_1001[i_1001][j_1001]);
    }
    patt_1(arr_1001, row_1001, col_1001);
    patt_2(arr_1001, row_1001, col_1001);
    patt_3(arr_1001, row_1001, col_1001);
    patt_4(arr_1001, row_1001, col_1001);
    return 0;
}