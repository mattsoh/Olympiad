// //     1
// //    / \
// //   2   3
// //   | \ |
// //   5 - 4

#include <bits/stdc++.h>
using namespace std;
const int N = 2505;
vector<int> adj[N];
int main(){
    int n,m;cin>>n>>m;
	for (int i = 0;i<m;i++){
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
    	adj[b].push_back(a);
	}   
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
		int dist[N];
		int par[N];
		memset(dist,0,sizeof(dist));
		memset(par,0,sizeof(par));
        dist[i] = 0;
        queue<int>tovisit;
        tovisit.push(i);
        while (!tovisit.empty()) {
            int x = tovisit.front();
            tovisit.pop();
            for (int j:adj[x]) {
                if (dist[j] == 0) {
                    dist[j] = dist[x]+1;
                    par[j] = x;
                    tovisit.push(j);
                }
                else if (par[x] != j && par[j] != x){
					cout<<x<<dist[x]<<j<<dist[j]<<endl;
                    ans = min(ans,dist[x]+dist[j]+1);
				}
            }
        }
    }
    if (ans == INT_MAX){
		cout<<-1;
	}else{
		cout<<ans;
	}
}