#include<stdio.h>

int m[100][100],s[100][100],d[100];
int n;

void matrix(int d[]){
    int i,j,k,l,q;
    for(i=0;i<=n;i++){
        scanf("%d",&d[i]);
    }
    for(i=1;i<=n;i++)
        m[i][i] = 0;
    
    for(l=2;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j = i+l-1;
            m[i][j] = 9999;
            for(k=i;k<=j-1;k++){
                q = m[i][k] + m[k+1][j]+d[i-1]*d[k]*d[j];
                if(q<m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main(){
    printf("Enter the no. of matrices\n");
    scanf("%d",&n);
    printf("Enter the value of d\n");
    matrix(d);
    printf("The maximum steps is %d\n",m[1][n]);

    return 0;
}