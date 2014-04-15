/*
 * doitagain.cpp
 * 2014/02/03 03:33:33
 *
 * Shubham Chaudhary < UE113090 >
 *
 */
#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Globals

// Functions
/*
 *
 * name: dfs
 * @param adjacency matrix, size of matrix, source<1-num>, dest(if 0, traverse graph)
 * @return none
 *
 */
void dfs(int **adjm,int num,int src,int dest){
    cout << "-------- DFS ------"<<endl;
    enum label_list{NEW, MARKED, DONE} label[num];
    //enum label_list label[num];
    for(int i=1;i<=num;++i)
        label[i]=NEW;
    //Traverse
    stack<int> s;
    s.push(src);
    while ( ! s.empty() ){
        int cur = s.top();
        s.pop();
        if(label[cur] == NEW){
            label[cur]=MARKED;
            cout << "Visited DFS: " << cur<<endl;
            if(cur == dest){
                cout << "Found\n";
                return;
            }
            for(int i=num;i>=1;--i){
                //cout << "Compared: "<<"adj["<<cur<<"]["<<i<<"] = "<<adjm[cur][i]<<endl;
                if(adjm[cur][i] == 1){
                    //cout << "Pushed: "<<i<<" because "<<"adj["<<cur<<"]["<<i<<"] = 1"<<endl;
                    s.push(i);
                }
            }
        }
    }//while not empty
}
/*
 *
 * name: bfs
 * @param adjacency matrix, size of matrix, source<1-num>, dest(if 0, traverse graph)
 * @return none
 *
 */
void bfs(int **adjm,int num,int src,int dest){
    cout << "-------- BFS ------"<<endl;
    enum label_list{NEW, MARKED, DONE} label[num];
    //enum label_list label[num];
    for(int i=1;i<=num;++i)
        label[i]=NEW;
    //Traverse
    queue<int> s;
    s.push(src);

    //list<int> set;
    //set.insert(src);

    while ( ! s.empty() ){
        int cur = s.front();// s.back();
        s.pop();    //remove oldest
        label[cur]=MARKED;
        cout << "Visited BFS: " << cur<<endl;
        if(cur == dest){
            cout << "Found\n";
            return;
        }
        for(int i=0;i<=num;++i){
            //cout << "Compared: "<<"adj["<<cur<<"]["<<i<<"] = "<<adjm[cur][i]<<endl;
            if(adjm[cur][i] == 1){
                if(label[i] == NEW){
                    label[i]=MARKED;
                    //cout << "Pushed: "<<i<<" because "<<"adj["<<cur<<"]["<<i<<"] = 1"<<endl;
                    s.push(i);
                }
            }
        }
    }//while not empty
}

// ----- Graph related function -----
/*
 *
 * name: allocate_graph Allocate memory to graph
 * @param size of new graph
 * @return integer adjacency matrix
 *
 */
int ** allocate_graph(int num){
    //Dynamic Allocation
    int **adjm=new int*[num+1];
    for(int i=0;i<num+1;++i){
        adjm[i]=new int[num+1];
    }
    return adjm;
}
/*
 * name: allocate_graph Allocate memory to graph
 * @param size of new graph
 * @return none
 */
void deallocate_graph(int **adjm,int num){
    //Dynamic Allocation
    for(int i=0;i<num+1;++i){
        //adjm[i]=remove int[num+1];
        delete adjm[i];
    }
    delete adjm;
}

void input_graph(int **adjm,int num){
    for(int i=1;i<=num;++i){
        for(int j=i;j<=num;++j){
            if(i==j){
                adjm[i][i]=0;
                continue;
            }
            printf("Enter #(%d,%d): ",i,j);
            cin >> adjm[i][j];
            adjm[j][i]=adjm[i][j];
        }
    }
}

// ### MAIN ###
int main(){
    /// INPUT
    int num=-1;
    cout << "Enter no of nodes: "; cin >> num;

    int **adjm = allocate_graph(num);
    input_graph(adjm,num);

    // variables
    int src=1; int dest=num;

    // menu
    //int choice;
    char choice;
    do{
        cout << "Enter choice: "; cin >> choice;
        switch(choice){
            case 'b': // breadth first
                bfs(adjm,num,src,dest);
                break;
            case 'd': //depth fs
                dfs(adjm,num,src,dest);
                break;
            case 's': //change source and destination
                cout << "Enter source: "; cin >> src;
                cout << "Enter destination: "; cin >> dest;
                break;
            case 'n': // change graph size
                deallocate_graph(adjm,num);
                cout << "Enter no of nodes: "; cin >> num;
                adjm=allocate_graph(num);
                input_graph(adjm,num);
                break;
            case 'q': // exit
                deallocate_graph(adjm,num);
                break;
            default:
                cout << "Looks like high school ain't over yet ! ! !\n";
                break;
        }
    }while(choice != 'q');;

    return 0;
}


