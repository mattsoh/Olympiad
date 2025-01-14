
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxW = -1;
const ll maxn = 50;
ll dp[maxn][maxn][maxn]; // no of items, weight
ll w;
ll waysdp[maxn][maxn];
ll weights(ll w, ll items, ll maxw){
    // cout<<w<<' '<<items<<endl;
    if (items < 0 || w < 0 || maxw < 0) {
        return 0;
    }
    if (dp[w][items][maxw] >= 0) return dp[w][items][maxw];
    if (w == 0 && items == 0 && maxw == 0) {
        return 1;
    }
    if (maxw == 0) {
        return 0;
    }
    ll sum = weights(w, items, maxw - 1);
    if (w >= maxw) sum += weights(w - maxw, items - 1, maxw);
    // cout << sum <<" check" << " " << w << " "<<items <<" "<<maxw<< endl;
    return dp[w][items][maxw] = sum;
}
ll ways(ll p, ll n){ // no of parcels, total no of items
    ll count = 0;
    if (p == 1){
        return weights(w,n, maxW);
    }
    // if (p == 1 || n == 1) return 1;
    if (waysdp[n][p] >= 0) return waysdp[n][p];
   
    for (ll i = 1;i<=n;i++){
            // cout<<i<<endl;
            if ( n-i>= 0) count += weights(w, i, maxW) * ways(p-1, n-i);
    }
    waysdp[n][p] = count;
    return count;
}
int main(){
    for (ll i = 0;i<maxn;i++){
        for (ll j = 0;j<maxn;j++){
            for (int k = 0; k < maxn; k++) {
                dp[i][j][k] = -1;
                waysdp[i][j] = -1;
            }
        }
    }
    ll p;cin>>p;
    cin>>maxW;
    ll n;cin>>n;
    cin>>w;
    cout<<ways(p,n)<<endl;
}