#include<stdio.h>
#include<stdlib.h>

int x[10];
int counter = 0;

void nq(int, int);
int place(int, int);

void nq(int k,int n){
    int i,j;
    for(i=1;i<=n;i++){
        if(place(k,i)==1){
            x[k] = i;
            if(k==n){
                counter++;
                printf("\nThe possible solution %d \n",counter);
                for(k=1;k<=n;k++){
                    printf("%d\t",x[k]);
                }
            }
            else{
                nq(k+1,n);
            }
        }
    }
}

int place(int k,int i){
    for(int j=0;j<=k-1;j++){
        if((x[j]==i) || abs(x[j]-i)==abs(j-k)){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    printf("Enter the numbers of queens\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        x[i]=0;
    }
    nq(1,n);
    return 0;
}