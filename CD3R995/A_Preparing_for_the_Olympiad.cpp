#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n;cin>>n;
    ll a[n], b[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    ll c = 0;
    for (ll i = 0;i<n;i++){
        if (i<n-1 && a[i] > b[i+1]){
            c+= a[i] - b[i+1];
        } else if (i == n-1){
            c+= a[i];
        }
    }
    cout<<c<<endl;
}
signed main(){
    ll t;cin>>t;
    while (t--) solve();
}