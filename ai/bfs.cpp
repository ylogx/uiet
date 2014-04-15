#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#define MAXNODES 20
using namespace std;
//********Global Variables*******
struct gnode{
    int ver;
    struct gnode * next;
};
//********Functions Used*********
void dispAlist(struct gnode **adj,int num);
void qdisplay(queue<int> q);
//*******************************
//%%%%%% Depth First Search %%%%%%%%%
void dfs(struct gnode *adj[],int num,int source,int dest){
    int level[MAXNODES]={-1};
    int *label=new int[num];//{-1};
    for(int i=0;i<num;i++)
        label[i]= -1;
    int parent[MAXNODES];
    stack<int> frontier;
    //queue<struct gnode *adj> q;
    int i,count=0;
    //initialisation
    i=source-1;     //XXX
    dest = dest -1;

    level[i]=0;     //level of source = 0
    label[i]=0;
    parent[i]=-1;   //parent source NULL(=intMax)

    frontier.push(i);
    //traversing
    while(frontier.empty() == false){
        //printf("isnotempty***");
        int u;
        u=frontier.top();
        frontier.pop();
        label[u]=1;
        //SEARCH
        printf("Comparing u=%d dest=%d \n",u,dest);
        if(u == dest){
            printf("Found\n");
            return;
        }
        //Look at nodes from the ele poped (NOTE: initially source)
        struct gnode *ua=adj[u];
        //Add all unseen(-1) ele adjacent to 'u' are in 'ua'
        while(ua != NULL){
            if(label[ua->ver] == -1){
                frontier.push(ua->ver);
                label[ua->ver]=0;
                level[ua->ver]=count;
                parent[ua->ver]=u;
            }
            ua = ua->next;
        }
        ++count;
    }
}
//%%%%%% Breadth First Search %%%%%%%%%
void bfs(struct gnode *adj[],int num,int source,int dest){
    int level[MAXNODES]={-1};
    int *label=new int[num];//{-1};
    for(int i=0;i<num;i++)
        label[i]= -1;
    int parent[MAXNODES];
    queue<int> frontier;
    //queue<struct gnode *adj> q;
    int i,count=0;
    //initialisation
    i=source-1;     //XXX
    dest = dest -1;

    level[i]=0;     //level of source = 0
    label[i]=0;
    parent[i]=-1;   //parent source NULL(=intMax)

    frontier.push(i);
    //traversing
    while(frontier.empty() == false){
        //printf("isnotempty***");
                printf("Adj List: ");
                dispAlist(adj,num);
        int u;
        u=frontier.front();
        frontier.pop();
        printf("%d:Popped %d\n",count,u+1);
        label[u]=1;
        //SEARCH
        printf("Comparing u=%d dest=%d \n",u+1,dest+1);
        if(u == dest){
            printf("Found\n");
            return;
        }
        //Look at nodes from the ele poped (NOTE: initially source)
        struct gnode *ua=adj[u];    //adj[i] is: struct gnode * & adj is (gnode**) a list of gnode pointers (gnode *s)
        int flag = 1;
        struct gnode ud;
        printf("adj[%d]=%d : ver=%d\n",u,adj[u],adj[0]->ver);
        if (adj[u] != NULL){
            ud= *adj[u];
            printf("ud set to adj\n");
        } else
            flag=0;
        //Add all unseen(-1) ele adjacent to 'u' are in 'ua'
        //while(ua != NULL){
        //    if(label[ua->ver] == -1){
        //        frontier.push(ua->ver);
        //        label[ua->ver]=0;
        //        level[ua->ver]=count;
        //        parent[ua->ver]=u;
        //    }
        //    ua = ua->next;    //XXX editing original values in adj
        //}
        printf("the flag=%d for u=%d\n",flag,u);
        while(flag == 1){
            printf("flag=%d for u=%d\n",flag,u);
            if(label[ud.ver] == -1){
                printf("%d:Pushing vertex %d\n",count,ua->ver + 1);
                frontier.push(ua->ver);
                label[ud.ver]=0;
                level[ud.ver]=count;
                parent[ud.ver]=u;
            }
            if(ud.next != NULL)
                ud = *(ud.next);
            else
                flag = 0;
        }
        ++count;
    }
}
void createGraph(struct gnode *adj[],int num){
    int i;
    for(i=0;i<num;i++){
        adj[i]=NULL;
    }
}
void inputGraph(struct gnode *adj[],int num){
    int i,noNode;
    for(i=0;i<num;i++){
        int j;
        struct gnode * last;
        printf("\nNo. of nodes in the adjacency list of node %d: ",i);
        scanf("%d",&noNode);
        for(j=0;j<noNode;j++){
            int input;
            printf("Enter node #%d: ",j);
            scanf("%d",&input);
            struct gnode *temp=(struct gnode *)malloc(sizeof(struct gnode));
            temp->ver=input;
            temp->next=NULL;
            if(adj[i]){
                last->next=temp;
                last=temp;
            }else{
                adj[i]=last=temp;
            }
        }
    }
}
void dispAlist(struct gnode *adj[],int num){
    int i;
    printf("\n");
    for(i=0;i<num;++i){
        while(adj[i] != NULL){
            printf("%d->%d\t",i+1,adj[i]->ver);
            adj[i] = adj[i]->next;
        }
        printf("\n");
    }
}

//############## Main Function ################
int main(){
    struct gnode * adj[MAXNODES];   //array of pointers
    int n;
    printf("\nEnter no. of nodes in the graph: ");
    scanf("%d",&n);
    createGraph(adj,n);
    inputGraph(adj,n);
    dispAlist(adj,n);

    int choice=1, dest=2;

    printf("Enter Destination: ");
    scanf("%d",&dest);
    //BFS
    bfs(adj,n,1,dest);
    //DFS
    //dfs(adj,n,1,dest);

    //printf("Enter 1/2/3: ");
    //scanf("%d",&choice);
    //while(choice != 3){
    //    switch(choice){
    //        case 1:
    //            printf("Enter Destination: "); scanf("%d",&dest);
    //            bfs(adj,n,1,dest);
    //            break;
    //        default:
    //            break;
    //    };
    //    printf("Enter 1/2/3: ");
    //    scanf("%d",&choice);
    //}
    return 0;
}
//############################################
//****Display Function**********
void qdisplay(queue<int> q) {
    int i;
    if(q.empty())
        printf("Queue is empty\n");
    else
    {
        printf("Queue is :\n");
        for (i = q.back(); i <= q.size(); ++i){
            printf("%d ",q.front());
            q.pop();
        }
        printf("\n");
    }
}
