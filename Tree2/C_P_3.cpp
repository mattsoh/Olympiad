#include <bits/stdc++.h>
using namespace std;
vector<int> adj[2][200004];
pair<int,int> dfs(int x, int from, int t){
    int depth = 0, best = x;
    for (auto i: adj[t][x]){
        if (i != from){
            pair<int,int>result = dfs(i,x,t);
            if (result.first+1 > depth){
                depth = result.first+1;
                best = result.second;
            }
        }
    }
    return {depth,best};
}
int main(){
    int n;cin>>n;
    for (int i = 1;i<n;i++){
        int a,b;cin>>a>>b;
        adj[0][a].push_back(b);
        adj[0][b].push_back(a);
    }
    // cout<<dfs(dfs(1, v, 0).second, vv, 0).second;
    int f = dfs(1,0,0).second;
    // cout<<ceil(dfs(f, vv, 0).first/2)<<endl;
    int farthest = dfs(f,0,0).first;
    // cout<<f<<farthest<<endl;
    int m;cin>>m;
    for (int i = 1;i<m;i++){
        int a,b;cin>>a>>b;
        adj[1][a].push_back(b);
        adj[1][b].push_back(a);
    }
    int farthest1 = dfs(dfs(1,0,1).second,0,1).first;
    // cout<<ceil(dfs(1, v1, 0).second/2)<<endl;
    // cout<<farthest<<' '<<farthest1<<endl;
    cout<<max((farthest+1)/2+(farthest1+1)/2+1, max(farthest, farthest1));
}