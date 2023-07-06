#include<stdio.h>

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main(){
    int i,n;
    printf("Enter the value of n\n");
    scanf("%d",&n);

    int arr[100];

    printf("Enter the element of array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    quickSort(arr,0,n-1);

    printf("Array after sorting the element is:");

    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}
