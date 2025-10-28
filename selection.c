//Selection Sort
#include<stdio.h>
#include<conio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i,j,min;
    for (i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        swap(&arr[min],&arr[i]);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0;i<size;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    clrscr();  // Clear screen

    int arr[10];
    int i,n;
    printf("Enter array size\n");
    scanf("%d",&n);
    printf("Enter %d array elements\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    selectionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    getch();  // Wait for key press before closing
    return 0;
}
