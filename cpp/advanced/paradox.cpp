#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <climits>
#include <cfloat>
#include <cassert>

using namespace std;
#define readint(n)      scanf("%d",&n)
#define readull(n)      scanf("%llu",&n)
#define readll(n)       scanf("%lld",&n)
#define readf(n)        scanf("%f",&n)
#define readd(n)        scanf("%lf",&n)
#define init(mem)       memset(mem,0,sizeof(mem))
#define ll              long long int
#define ull             unsigned long long int

int main(){
    int n,implies[101],state[101];
    vector<int>implied_by[101];
    bool vis[101],claims[101];
    string str;
    while(1){
        readint(n);
        if(n==0)return 0;

        for(int i=1;i<=n;i++){
            vis[i]=false;
            claims[i]=false;
            state[i]=false;
            implied_by[i].clear();
        }

        stack<int> q;
        for(int i=1;i<=n;i++){
            readint(implies[i]);
            cin>>str;
            if(str[0]=='t'){
                claims[i]=true;
            }
            implied_by[implies[i]].push_back(i);
            q.push(i);
        }

        bool good=true;

        while(q.size()>0){
            if(vis[q.top()]){
                q.pop();
                continue;
            }
            int curr=q.top();
            q.pop();

            vis[curr]=true;
            bool imp=not(state[curr] xor claims[curr]);
            if(!vis[implies[curr]]){
                state[implies[curr]]=imp;
                q.push(implies[curr]);
            }
            else if(state[implies[curr]]!=imp){
                good=false;
                break;
            }
            // now check impliers
            for(int i=0;i<implied_by[curr].size();i++){
                if(!good) break;
                imp=not(state[curr] xor claims[implied_by[curr][i]]);
                if(!vis[implied_by[curr][i]]){
                    state[implied_by[curr][i]]=imp;
                    q.push(implied_by[curr][i]);
                }
                else if(state[implied_by[curr][i]]!=imp){
                    good=false;
                    break;
                }
            }
        }
        if(good){
            printf("NOT PARADOX\n");
        }
        else{
            printf("PARADOX\n");
        }
    }
    return 0;
}

