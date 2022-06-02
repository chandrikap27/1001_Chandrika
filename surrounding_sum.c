/*
WAP function that will sum the surrounding elements of a given element in the matrix.
*/
#include<stdio.h>
#include<stdlib.h>
int row,col;
int add_surrounding_elements(int **a,int r,int c)
{
    int sum=0;
    if(r==0 || r==(r-1) || c==0 || c==(c-1))
    {
        if(r==0 && c==0)
            sum+=a[1][c] + a[r][1];
        else if (r==0 && c==(c-1))
            sum+=a[r][c-1] + a[r +1][c];
        else if (r==(r-1) && c==0)
            sum+=a[r][c+1] + a[r - 1][c];
        else if (r==c==(c-1))
            sum+=a[r][c-1] + a[r - 1][c];
        else if (r==0 && c>0 && c<(c-1))
            sum+=a[r][c-1] + a[r][c +1] + a[r +1][c];
        else if (c==0 && r>0 && r<(r-1))
            sum+=a[r -1][c] + a[r ][c+1] + a[r + 1][c];
        else if (r==(r-1) && c>0 && c<(c-1))
            sum+=a[r][c-1] + a[r ][c + 1] + a[r - 1][c];
        else if (c==(c -1) && r > 0 && r<(r-1))
            sum+=a[r][c-1] + a[r +1][c] + a[r - 1][c];
    }
    else
    sum+=a[r][c+1] + a[r][c - 1] + a[r +1][c] +a[r-1][c];
    return sum;    
}
int main()
{
    printf("Enter no of rows : ");
    scanf("%d",&row);
    printf("Enter no of columns : ");
    scanf("%d",&col);
    int **arr;
    arr=(int **)malloc(row * sizeof(int *));
    if(arr==NULL)
        printf("No memory allocated !");
    for (int i = 0; i < row; i++)
        arr[i] = (int *)malloc(col * sizeof(int));
    printf("Enter Elements of Array :\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            scanf("%d", &arr[i][j]);
    }
    int r,c,num;
    printf("Enter the number whose surrounding sum is to be calculated : " );
    scanf("%d",&num);
    for(int i=0;i<row;i++)
    {
        for(int j =0 ;j<col;j++)
        {
            if(num==*(*(arr + i)+j))
            {
                r=i;
                c=j;
            }
        }
    }
    int sum = add_surrounding_elements(arr,r,c);
    printf("\n The sum of %d's surrounding elements is %d",num,sum);
    return 0;
}