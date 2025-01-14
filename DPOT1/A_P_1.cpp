#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define white 0
#define black 1
typedef long long ll;
const ll maxn = 1e5+10;
ll ways[maxn][2];
vector<ll> adj[maxn];
const ll mod = 1e9+7;
void sch(ll x, ll from){
    if (ways[x][0] == 0){
        ll count_w = 1, count_b = 1;
        for (auto i:adj[x]){
            if (i == from){
                continue;
            }
            sch(i,x);
                count_w *= (ways[i][0]+ways[i][1]);
                count_b *= ways[i][0];
        }
        ways[x][0] = count_w;
        ways[x][1] = count_b;
    }
}
int main(){
    ll n;cin>>n;
    for (ll i = 1;i<n;i++){
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (ll i = 1;i<=n;i++){
        memset(ways[i],0,sizeof(ways[i]));
    }
    sch(1,1);
    cout<<(ways[1][0]+ways[1][1])%mod<<endl;
    return 0;
}