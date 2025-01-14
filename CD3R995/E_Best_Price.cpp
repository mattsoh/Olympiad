#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,k;cin>>n>>k;
    vector<ll> A(n), B(n), cand;
    for(ll i=0;i<n;i++){cin>>A[i];cand.push_back(A[i]);}
    for(ll i=0;i<n;i++){cin>>B[i];cand.push_back(B[i]);}
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(cand.begin(),cand.end());
    cand.erase(unique(cand.begin(),cand.end()),cand.end());
    ll ans=0;
    for(auto c:cand){
        ll pos=n-(lower_bound(A.begin(),A.end(),c)-A.begin());
        ll buy=n-(lower_bound(B.begin(),B.end(),c)-B.begin());
        ll neg=buy-pos;
        if(neg<=k) ans=max(ans,c*buy);
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
    ll t;cin>>t;while(t--)solve();
    return 0;
}