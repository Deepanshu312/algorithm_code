#include<stdio.h>

int BinarySearch(int a[], int low, int high, int key){
    if(low==high){
        if(key == a[low]){
            return low;
        }
        else{
            return 0;
        }
    }
    else{
        int mid = (low+high)/2;
        if(key==a[mid]){
            return mid;
        }
        else if(key < a[mid]){
            return BinarySearch(a,low,mid-1,key);
        }
        else{
            return BinarySearch(a,mid+1,high,key);
        }
    }
}

int main(){
    int n,i,x,result;
    int A[100];
    printf("Enter the no. of elements\n");
    scanf("%d",&n);
    printf("Enter the element of array\n");
    for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    }

    printf("Enter the key:");
    scanf("%d",&x);

    result = BinarySearch(A,0,n-1,x);
    if(result == 0){
        printf("Element not found\n");
    }
    else{
        printf("Element found in location %d \n",result+1);
    }
    return 0;
}