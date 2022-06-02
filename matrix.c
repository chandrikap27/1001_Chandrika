/*20051001_Lab-1_Q3
    3) WAP program to do the following operations on matrix.
a)Find the number of zero’s
b)Find the sum of all elements above the main diagonal  
c)Display all the diagonal elements.
d)Display the matrix in a row major order
e)Display the matrix in a column major order.
*/
#include <stdio.h>
int main()
{   int n_1001;
    printf("enter no of rows \n");
    scanf("%d",&n_1001);
    int a_1001[n_1001][n_1001];
    int c_1001=0,sum_1001=0;
    printf("enter the elements of the matrix: \n");
    for(int i_1001=0;i_1001<n_1001;i_1001++)
    {   
        for(int j_1001=0;j_1001<n_1001;j_1001++)
        {
            printf("element (%d,%d)",i_1001+1,j_1001+1);
            scanf("%d",&a_1001[i_1001][j_1001]);
        }
    }
    printf("enter your choice :\n");
    printf("1)Find the number of zeros\n");
    printf("2)Find the sum of all elements above the main diagonal\n");
    printf("3)Display all the diagonal elements\n");
    printf("4)Display the matrix in a row major order\n");
    printf("5)Display the matrix in a column major order.\n\n");
    int ch_1001;
    scanf("%d",&ch_1001);
    switch (ch_1001)
    {
        case 1:  //find no of zeros
           for(int i_1001=0;i_1001<n_1001;i_1001++)
        {
            for(int j_1001=0;j_1001<n_1001;j_1001++)
            if(a_1001[i_1001][j_1001]==0)
            c_1001++;
        }
        printf("no of zeros :%d",c_1001);
        break;
        case 2:          //sum of elements above diagonal
            for(int i_1001=0;i_1001<n_1001;i_1001++)
            {
                for(int j_1001=0;j_1001<n_1001;j_1001++)
                    if(j_1001>i_1001)
                        sum_1001+=a_1001[i_1001][j_1001];
              }
            printf("sum of elements above diagonal: %d",sum_1001);
        break;
        case 3:      //display all the diagonal element
            printf("diagonal elements are: \n");
            for(int i_1001=0;i_1001<n_1001;i_1001++)
            {
                for(int j_1001=0;j_1001<n_1001;j_1001++)
                    if(i_1001==j_1001)
                        printf("%d ",a_1001[i_1001][j_1001]); 
            }
            printf("\n");
        break;
        case 4:     //row major
            printf("row major :\n");
            for(int i_1001=0;i_1001<n_1001;i_1001++)
            {
                for(int j_1001=0;j_1001<n_1001;j_1001++)
                    printf("%d ",a_1001[i_1001][j_1001]);
                printf("\n");
            }
        break;
        case 5:    //column major
             printf("column major :\n");
             for(int j_1001=0;j_1001<n_1001;j_1001++)
             {
                for(int i_1001=0;i_1001<n_1001;i_1001++)
                    printf("%d ",a_1001[i_1001][j_1001]);
             printf("\n");
             }          
         break;
    
         default:
             printf("WRONG CHOICE");
    }   
    return 0;
}
