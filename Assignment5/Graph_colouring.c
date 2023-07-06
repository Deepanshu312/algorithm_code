#include<stdio.h>

int g[10][10],x[10];
void next_col(int);

void main(){
    int v,i,j;
    printf("Enter the no. of vertices\n");
    scanf("%d",&v);

    printf("Enter the adjacency matrix\n");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            scanf("%d",&g[i][j]);
        }
    }
    for(i=0;i<v;i++){
        next_col(i);
    }

    printf("colours assigned\n");
    for(i=0;i<v;i++){
        printf("%d -> %d\n",i,x[i]);
    }
}

void next_col(int k){
    int i;
    x[k]=1;
    for(i=0;i<k;i++){
        if(g[i][k]!= 0 && x[k]==x[i])
            x[k] = x[i] + 1;
    }
}
