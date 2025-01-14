#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100002];
// double length[100002] = {-1};
double dfs(int x, int parent){
    if (adj[x].size() == 1 && x != 1){
        // length[/x] = 0;
        return 0;
    }
    double sum = 0, count = 0;
    for (auto i:adj[x]){
        if (i != parent){
            // dfs(i,x);
            sum+=dfs(i,x);
            count++;
        }
    }
    return sum/count + 1;
}
int main(){
    int n;cin>>n;
    if (n == 1){
        cout<<0;
        return 0;
    }
    for (int i = 1;i<n;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<fixed<<setprecision(15)<<dfs(1,0);
}