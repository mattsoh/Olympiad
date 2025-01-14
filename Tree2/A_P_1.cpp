#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100002];
int dfs(int x, int from,){
    int children = 0, req = 0;
    for (auto i: adj[x]){
        if (i != from){
            children++;
            req += dfs(i, x)+1;
        }
    }
    int curr = 1;
    while (curr < children+1){
        curr*=2;
        req++;
    }
    return req;
}
int main(){
    int n;cin>>n;
    for (int i = 1;i<n;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<dfs(1, 0)<<endl;
}