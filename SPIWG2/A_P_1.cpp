#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
const ll maxn = 1e5 + 10;
ll dist[maxn], par[maxn];
vector<pair<ll,ll>> adj[maxn];
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    ll n,m;cin>>n>>m;
    for (ll i = 0;i<m;i++){
        ll a,b,w;cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    for (ll i = 0;i<=n;i++){
        dist[i] = -1;
        par[i] = -1;
    }
    dist[1] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,1}); 
    while (!q.empty()){
        pair<ll,ll> x = q.top();q.pop();
        if (x.fi == dist[x.se]){
            for (auto i:adj[x.se]){
                if (dist[i.fi] == -1 || dist[i.fi] > x.fi + i.se){
                    dist[i.fi] = x.fi + i.se;
                    par[i.fi] = x.se;
                    q.push({dist[i.fi],i.fi});
                }
            }
        }
    }
    if (dist[n] == -1){
        cout<<-1<<endl;
    }else{
        ll x = n;
        vector<ll>ans;
        while (x!=1){
            x = par[x];
            ans.push_back(x);
        }
        reverse(ans.begin(),ans.end());
        for (auto i:ans){
            cout<<i<<' ';
        }
        cout<<n<<' '<<endl;
    }
}