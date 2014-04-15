#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//Global
int num;
int adjm[20][20];
enum label_list{NEW, MARKED, DONE};

//Fun
void dfs(int src,int dest){
    enum label_list label[num];
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
            for(int i=num;i>=1;--i){
                //cout << "Compared: "<<"adj["<<cur<<"]["<<i<<"] = "<<adjm[cur][i]<<endl;
                if(adjm[cur][i] == 1){
                    cout << "Pushed: "<<i<<" because "<<"adj["<<cur<<"]["<<i<<"] = 1"<<endl;
                    s.push(i);
                }
            }
        }
    }//while not empty
}
void bfs(int src,int dest){
    enum label_list label[num];
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
        for(int i=0;i<=num;++i){
            //cout << "Compared: "<<"adj["<<cur<<"]["<<i<<"] = "<<adjm[cur][i]<<endl;
            if(adjm[cur][i] == 1){
                if(label[i] == NEW){
                    label[i]=MARKED;
                    cout << "Pushed: "<<i<<" because "<<"adj["<<cur<<"]["<<i<<"] = 1"<<endl;
                    s.push(i);
                }
            }
        }
    }//while not empty
}
int main(){
    /// INPUT
    cout << "Enter no of nodes: ";
    cin >> num;
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

    int dest=2;
    cout << "Enter destination: ";
    cin >> dest;
    //dfs
    cout << "-------- DFS ------"<<endl;
    dfs(1,dest);
    cout << "-------- BFS ------"<<endl;
    bfs(1,dest);
    return 0;
}


