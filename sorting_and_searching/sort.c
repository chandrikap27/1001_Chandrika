#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int *A, int n)
{
    int temp;
    int isSorted = 0,c=0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("Working on pass number %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                c++;
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    printf("no of comparisions in bubble sort = %d\n", c);
}
void selectionSort(int *A, int n)
{
    int indexOfMin, temp,c=0;
    printf("Running Selection sort...\n");
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                c++;
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
    printf("no of comparisions in selection sort = %d\n", c);

}
void insertionSort(int *A, int n)
{
    int key, j,c=0;
    printf("Running Insertion sort...\n");
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {   
            c++;
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
    printf("no of comparisions in insertion sort = %d\n", c);

}

void printArray(int *A, int n)
{
    printf("\nsorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n\n");
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
    int ch;
    do
    {
        printf("Enter your choice: ");
        printf("\n1.bubble sort\n2.selection sort\n3.insertion sort\n4.print\n5.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            bubbleSort(a, n);
            break;
        case 2:
            selectionSort(a, n);
            break;
        case 3:
            insertionSort(a, n);
            break;
        case 4:
            printArray(a, n);
            break;
        
        }
    } while (ch != 5);
}