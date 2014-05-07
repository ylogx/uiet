//Dijkstra's Algorithm
#include <stdio.h>

int main(){
    int size,i,j;
    int weightMat[50][50];  //weight matrix
    int vsrc;
    int visited[50]={0};
    int dist[50];
    printf("\nEnter no of nodes: ");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("Enter weight[%d][%d]: ",i,j);
            scanf("%d",&weightMat[i][j]);
        }
    }
    printf("\n");
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("%d\t",weightMat[i][j]);
        }
        printf("\n");
    }
    printf("\n\nEnter Source Vertex: ");
    scanf("%d",&vsrc);
    for(i=0;i<size;i++){
        dist[i]=weightMat[vsrc][i];
    }
    visited[vsrc]=1;
    dist[vsrc]=0;
    for(i=1;i<size;i++){
        //choose vertex closest
        //~ int min=weightMat[i][0];
        //~ for(j=0;j<size;j++){
            //~ if(weight[i][j]<min)
                //~ min=weight[i][j];
        //~ }
        int min=0;  //vertex adjacent with min wt
        int minWt=weightMat[i][0];
        for(j=0;j<size;j++){
            if(!visited[j]){
                if(minWt>weightMat[i][j]){
                    min=j;
                    minWt=weightMat[i][j];
                }
            }
        }
        visited[min]=1;
        for(j=0;j<size;j++){
            if(!visited[j]){
                if(dist[j]>dist[min]+weightMat[min][j]){
                    dist[j]=dist[min]+weightMat[min][j];
                }
            }
        }
    }

    //print
    printf("\n");
    for(i=0;i<size;i++){
        //printf("%d->%d: %d\n",vsrc,i,dist[i]);
        printf("%d->%d: %d\n",vsrc+1,i+1,dist[i]);
    }
    return 0;
}

