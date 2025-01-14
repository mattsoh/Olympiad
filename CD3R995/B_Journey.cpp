#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,a[3];cin>>n;
    for(ll i=0;i<3;i++) cin>>a[i];
    ll total = a[0] + a[1] + a[2];
    ll c = 0;
    c = n/total * 3;
    n %= total;
    while (n > 0){
        n -= a[(c%3)];
        c++;
    }
    cout<<c<<endl;
}
signed main(){
    ll t;cin>>t;
    while (t--) solve();
}