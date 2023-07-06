#include<stdio.h>
#include<stdlib.h>

int a[1000], d[1000][1000];

void bellman(int v,int s){
    int i,j,k,rel;
    for(i=1;i<=v;i++){
        a[i] = 9999;
    }
    a[s] = 0, rel = v-1;
    for(i=1;i<=rel;i++){
        for(j=1;j<=v;j++){
            for(k=1;k<=v;k++){
                if(a[j]+d[j][k]<a[k]){
                    a[k] = a[j] + d[j][k];
                }
            }
        }
    }
}

void main(){
    int i,j,n,x,y,v,edge,s;
    printf("Enter the vertices:");
    scanf("%d",&v);
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            if(i==j){
                d[i][j] = 0;
            }
            else
                d[i][j] = 9999;
        }
    }

    printf("Enter the connection:\n");
    scanf("%d",&n);
    printf("Enter edge value:\n");
    for(i=1;i<=n;i++){
        scanf("%d %d %d",&x,&y,&edge);
        d[x][y] = edge;
    }
    printf("Enter the source vertex:");
    scanf("%d",&s);
    bellman(v,s);
    printf("shortest path:");
    for(i=1;i<=v;i++){
        printf("%d to %d --> %d\n",s,i,a[i]);
    }
}