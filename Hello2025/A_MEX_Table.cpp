#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,m; cin>>n>>m;
    cout<<max(n,m)+1<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll t;cin>>t;
    while (t--) solve();
    return 0;
}