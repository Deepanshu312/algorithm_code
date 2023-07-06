#include<stdio.h>
#include<limits.h>
int max(int *arr, int res, int n){
    if(n==0)
        return res;
    else if(res<arr[0])
        res = arr[0];
    return max(arr+1,res,n-1);
}

int min(int *arr, int res, int n){
    if(n==0)
        return res;
    else if(res>arr[0])
        res = arr[0];
    return min(arr+1, res, n-1);
}

int main(){
    int A[100],n;
    printf("Enter the no. of elements\n");
    scanf("%d",&n);
    printf("Enter the element of array\n");
    for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
    }

    printf("Maximum = %d \n Minimum = %d \n",max(A,INT_MIN,n),min(A,INT_MAX,n));

    return 0;
}