#include <bits/stdc++.h>
using namespace std;
const int maxn = 50002,maxk = 502;
int ways[maxn][maxk];

int depth[maxn];
vector<int> adj[maxn];
int find_depth(int x){
    if (depth[x] == 0){
        for (auto i:adj[x]){

        }
    }
}
int sch(int x, int dist, int from){
    if (ways[x][dist] == 0){
        for (auto i: adj[x]){
            if (i != from){

            }
        }
    }
}
int main(){
    int n,k;cin>>n>>k;
    for (int i = 1;i<n;i++){
        int a,b;cin>>a>>b;
    }
    memset(depth,0,sizeof(depth));
    for (int i = 1;i<=n;i++){
        memset(ways[i],0,sizeof(ways[i]));
    }
}