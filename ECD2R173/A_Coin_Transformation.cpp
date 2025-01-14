#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
void solve(){
    ll n; cin>>n;
    ll k = 0;
    while(n > 3){
        n /= 4;
        k++;
    }
    ll result = 1LL << k;
    cout << result << "\n";
}
signed main(){
    ll t;cin>>t;
    while (t--) solve();
}