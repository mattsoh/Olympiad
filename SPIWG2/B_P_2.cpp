#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int maxn = 10002;
int dist[maxn];
vector<pair<int,int>> adj[maxn];
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    for (int i = 0;i<m;i++){
        int a,b,w;cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    for (int i = 0;i<=n;i++){
        dist[i] = -1;
    }
    dist[1] = 0;    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,1}); 
    while (!q.empty()){
        pair<int,int> x = q.top();q.pop();
        if (x.fi == dist[x.se]){
            for (auto i:adj[x.se]){
                if (dist[i.fi] == -1 || dist[i.fi] > x.fi + i.se){
                    dist[i.fi] = x.fi + i.se;
                    q.push({dist[i.fi],i.fi});
                }
            }
        }
    }
    if (dist[n] == -1){
        cout<<-1<<endl;
    }else{
        int x = 1;
        cout<<x<<' ';
        while (x!=n){
            x = par[x];
            cout<<x<<' '; 
        }
    }
}