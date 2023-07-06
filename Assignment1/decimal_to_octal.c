#include<stdio.h>
void oct(int n){
    int a;
    while(n>0){
        a = n%8;
        n = n/8;
        printf("%d",a);
    }
}

int main(){
    int n;
    printf("Enter a no.:");
    scanf("%d",&n);
    oct(n);
    return 0;
}