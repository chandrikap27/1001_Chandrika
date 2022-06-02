#include <stdio.h>
#include <stdlib.h>
void quicksort(int A[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(A[i]<=A[pivot]&&i<last)
            i++;
         while(A[j]>A[pivot])
            j--;
         if(i<j){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
         }
      }

      temp=A[pivot];
      A[pivot]=A[j];
      A[j]=temp;
      quicksort(A,first,j-1);
      quicksort(A,j+1,last);

   }
}

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("enter the size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("enter array element: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
   printArray(a,n);
   printf("\nAter quick sort : \n");
   quicksort(a,0,n-1);
   printArray(a,n);
}