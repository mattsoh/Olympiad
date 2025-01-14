#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200004];
bool v[200004] = {false},v1[200004] = {false};
pair<int,int> dfs(int x, int from){
    int depth = 0, best = x;
    for (auto i: adj[x]){
        if (i != from){
            pair<int,int>result = dfs(i,x);
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
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int farthest = dfs(1, 0).second;
    cout<<dfs(farthest, 0).first;
}