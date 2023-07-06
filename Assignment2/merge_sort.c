#include<stdio.h>

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergesort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergesort(A, low, mid);
        mergesort(A, mid+1, high);
        merge(A, mid, low, high);
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

    mergesort(arr,0,n-1);

    printf("Array after sorting the element is:");

    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}
