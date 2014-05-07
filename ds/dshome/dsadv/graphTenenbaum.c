/*
 *      Tennanbaum: Pg. #518
 * Start: Tue Feb 19 02:41:47 IST 2013
 * Finish:Tue Feb 19 03:28:34 IST 2013
 */
#include<stdio.h>

//*************Representation of Graphs********************
#define MAXNODES 50
struct node{
    int info;   //information associated with each node
};
struct arc{     //---represent every possible pair of nodes---
    int adj;    //information associated with each arc
                //g.arcs[i][j].adj is true if j adjacent to i else false
};
struct graph{
    struct node nodes[MAXNODES];
    struct arc arcs[MAXNODES][MAXNODES];    //adjacency matrix
};
struct graph g;
//*********************************************************



int main(){
    scanf("%d",&n);     //no of cities
    //create n nodes and label them from 0 to n-1
    scanf("%d %d",&a,&b);   //seek path from a to b
    scanf("%d",&nr);    //no of roads to take
    while(scanf("%d %d",&city1,&city2)!=EOF){
        join(city1,city2);
    }
    if(findPath(nr,a,b)){   //TODO ternary
        printf("Yes, A path exists from %d to %d in %d steps\n",a,b,nr);
    } else{
        printf("No path exists from %d to %d in %d steps\n",a,b,nr);
    }
    return 0;
}
//--------ALGORITHM for Problem---------
int findPath(int a,int b){
    if(k==1)    //search for apath of length 1
        return(adjacent(a,b));
    //determine if there is a path through c
    for(c=0;c<n;++c){
        if(adjacent(a,c)&&findPath(k-1,c,b)){
            return (TRUE);
        }
    }
    return(FALSE);  //assume no path exists
}

//============ F U N C T I O N S ==================
void join(int adj[][MAXNODES],int node1,int node2){
    /// Add an arc form node1 to node2
    adj[node1][node2]=TRUE;
}
void remv(int adj[][MAXNODES],int node1,int node2){
    /// Delete arc from node1 to node2 if one exists
    adj[node1][node2]=FALSE;
}
int adjacent(int adj[][MAXNODES],int node1,int node2){
    return((adj[node1][node2]==TRUE)?TRUE:FALSE);
}







/*
//----------Representation of Weighted Graphs--------------
#define MAXNODES 50
struct nodeWt{
    int info;   //information associated with each node
};
struct graph{
    struct node nodes[MAXNODES];
    struct arc arcs[MAXNODES][MAXNODES];    //adjacency matrix
};
struct graph g;

//+++++++weighted graph with fixed no. of nodes+++++++++++++
struct arcWt{     //---represent every possible pair of nodes---
    int adj;    //information associated with each arc
    int weight; //g.arcs[i][j].adj is true if j adjacent to i else false
};
struct arcWt g[MAXNODES][MAXNODES];
//-----------------------------------------------------------

//============ F U N C T I O N S ==================
void joinWt(struct arc g[][MAXNODES],int node1,int node2,int wt){
    g[node1][node2].adj=TRUE;
    g[node1][node2].weight=wt;
}
void remvWt(){};
*/
