#include<stdio.h>
int arr[20];
int adj[20][20];
int rear=0;
int count=0;
int  front=0;
int n,i,j;
int p = 1;
int queue[20];
void bfs(int );
int unvisited(int );
void insert(int );
int delete();
void display();
int main(){
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency path available or not:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    bfs(1);
    display();
    return 0;
}

void bfs(int v){
    int m;
    if(front == 0){
        insert(v);
    }
    for(j=1;j<=n;j++){
        if(adj[v][j] == 1){
            if(unvisited(j)){
                insert(j);
            }
        }
    }
    m = delete();
    count++;
    arr[p] = m;
    p++;
    if(count<=n){
        bfs(m);
    }
}

int unvisited(int v){
    for(i=0;i<front;i++){
        if(v==queue[i]){
            return 0;
        }
    }
    return 1;
}

void insert(int v){
    queue[front] = v;
    front++;
}

int delete(){
    rear = rear+1;
    return queue[rear - 1];
}

void display(){
    for(i=1;i<=n;i++){
        printf("%d ",arr[i]);
    }
}

