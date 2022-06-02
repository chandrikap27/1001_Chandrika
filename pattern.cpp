#include <stdio.h>
#include<stdlib.h>
int patt_1(int** a,int r,int c)
{
    for(int i=0;i<r;i++)
    {
      
        for(int j=0;j<i;j++)
        //return **((a+i)+j);
        printf("%d",((a+i)+j));
        printf("\n");
    }
}
int patt_2(int**a,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c-i;j++)
            printf(" ");
        for(int x=i;x>0;x--)
            printf("%d",((a+i)+(c-x)));
        printf("\n");    
    }
}
int patt_3(int**a,int r,int c)
{
    for(int i=0;i<r-1;i++)
    {
        for(int j=0;j<i+1;j++)
        printf(" ");
        for(int x=i+1;x<c;x++)
            printf("%d",((a+i)+x));
        printf("\n");
    }
}
int patt_4(int**a,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c-i;j++)
            printf("%d",((a+i)+j));
        printf("\n");    
    }
}
int main()
{
   int row,col;
   printf("Enter Row Number : ");
   scanf("%d",&row);
   printf("Enter Column Number : ");
   scanf("%d",&col);
   int** arr;
   arr=(int**)malloc(row*sizeof(int*));
   for(int i=0;i<row;i++)
   arr[i]=(int*)malloc(col*sizeof(int));
   printf("Enter Elements of Array :\n");
   for(int i=0;i<row;i++)
   {
       for(int j=0;j<col;j++)
       scanf("%d",&arr[i][j]);
   }
   patt_1(arr,row,col);
   patt_2(arr,row,col);
   patt_3(arr,row,col);
   patt_4(arr,row,col);
   return 0;
}