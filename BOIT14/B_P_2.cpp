#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2010, mod = 1e9+7;
ll a[maxn];
ll dp[maxn][maxn]; // i is the vertex, k is the no of values of a[j] > 0 (not -1) j > i
signed main(){
    cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(0);
    if (fopen("GRAPH.INP", "r")) {
        freopen("GRAPH.INP", "r", stdin);
        freopen("GRAPH.OUT", "w", stdout);
    }
    ll n,b;cin>>n>>b;
    for (ll i = 0;i<n;i++){
        cin>>a[i];
    }
    dp[n][0] = 1;
    for (ll i = n;i>=1;i--){ // for vertex
        for (ll k = 0;k<=b;k++){ // number of possible connected edges from other with higher idx
            if (a[i-1] == -1){
                if (min(i-1,b-k) >=0){
                    dp[i-1][k] = ((dp[i-1][k] + dp[i][k])) % mod;
                }
                if (min(i-1,b-k) > 0){
                    dp[i-1][k+1] = (dp[i-1][k+1] + dp[i][k]* min(i-1,b-k)%mod) % mod;
                }
                // for (ll j = 0;j<=min(i-1,b-k);j++){ // iterate through all possible next a[i]
                    
                // }
            } else if (a[i-1] == 0){
                dp[i-1][k] = (dp[i-1][k] + dp[i][k]) % mod;
            } else {
                if (a[i-1] <= b-k) dp[i-1][k+1] = (dp[i-1][k+1] + dp[i][k]) % mod;
            }
        }
    }
    ll cnt = 0;
    for (int i = 0;i<=b;i++){
        cnt = (cnt + dp[0][i]) % mod;
    }
    cout<<cnt%mod<<endl;
}