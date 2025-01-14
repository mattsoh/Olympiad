#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n;cin>>n;
    ll a[n], b[n];
    for (ll i=0;i<n;i++){
        cin>>a[i];
    }
    for (ll i=0;i<n;i++){
        cin>>b[i];
    }
    bool notposs = false;
    for (ll i = 0;i<n;i++){
        if (a[i]<b[i]){
            for (ll j=0;j<n;j++){
                if (i!=j){
                    a[j] -= b[i] - a[i];
                    if (a[j]<b[j]){
                        cout<<"NO"<<endl;
                        notposs = true;
                        break;
                    }
                    if (notposs) break;
                }
                if (notposs) break;
            }
            a[i] = b[i];
            if (notposs) break;
        }
        if (notposs) break;
    }
    if (!notposs) cout<<"YES"<<endl;
}
signed main(){
    ll t;cin>>t;
    while (t--) solve();
}