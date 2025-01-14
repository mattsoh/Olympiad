#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
vector<int>adj[maxn];
int anc[maxn][20];
void dfs(int x, int from){
    anc[x][0] = from;
    for (int i = 1;i<20;i++){
        anc[x][i] = anc[anc[x][i-1]][i-1];
    }
    for (auto i: adj[x]){
        if (i!=from) dfs(i,x);
    }
}
int main(){
    int n,q;cin>>n>>q;
    for (int i = 1;i<n;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for (int i = 0;i<q;i++){
        int v,k;cin>>v>>k;
        for (int i= 19;i>=0;i--){
            if (k&(1LL<<i)){
               v=anc[v][i]; 
            }
        }
        cout<<v<<endl;
    }
}