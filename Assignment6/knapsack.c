#include<stdio.h>

struct sack{
    double weight;
    double cost;
    double ratio;
};

void sort(struct sack *s,int n){
    struct sack temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(s[j].ratio<s[j+1].ratio){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void knapsack(struct sack *s,int n,double bagSize){
    int i;
    double a[10],u = bagSize,tp = 0;
    for(i=0;i<=n-1;i++){
        if(s[i].weight>u){
            break;
        }
        else{
            a[i]=1;
            tp += s[i].cost;
            u -= s[i].weight;
        }
    }
    if(i<n){
        a[i] = u/s[i].weight;
        tp += a[i]*s[i].cost;
        printf("Maximum profit = %lf\n",tp);
    }
}

int main(){
    int n;
    struct sack s[10];
    double bagSize;

    printf("Enter the number of items:\n");
    scanf("%d",&n);
    printf("Enter the capacity of bag:\n");
    scanf("%lf",&bagSize);
    for(int i=0;i<n;i++){
        printf("Enter the weight of item: ");
        scanf("%lf",&s[i].weight);
        printf("Enter the cost of items:");
        scanf("%lf",&s[i].cost);
        s[i].ratio = s[i].cost/s[i].weight;
    }
    sort(s,n);
    knapsack(s,n,bagSize);
    return 0;
}

