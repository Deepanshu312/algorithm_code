#include<stdio.h>

void foo(int);
int a[10][10];

void main(){
    int i,j,n;
    printf("Enter the no. of vertices\n");
    scanf("%d",&n);

    printf("Now enter the adjacency matrices\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    foo(n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
            printf("\n");
    }
}

void foo(int n){
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][k]+a[k][j]<a[i][j])
                    a[i][j] = a[i][k]+a[k][j];
}