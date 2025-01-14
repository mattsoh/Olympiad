#include <bits/stdc++.h>
using namespace std;
typedef long long ll;   
void solve(){
    ll n,x,y;cin>>n>>x>>y;
    vector<ll> a(n);
    ll summ=0; 
    for(ll i=0;i<n;i++){cin>>a[i];summ+=a[i];}
    ll L=summ-y, R=summ-x;
    sort(a.begin(),a.end());
    
    ll cnt=0;
    for(ll i=0;i<n;i++){
        ll lowVal=L-a[i], highVal=R-a[i];
        ll lowPos=lower_bound(a.begin()+i+1,a.end(),lowVal)-a.begin();
        ll highPos=upper_bound(a.begin()+i+1,a.end(),highVal)-a.begin();
        cnt+=(max(0LL,highPos-lowPos));
    }
    cout<<cnt<<endl;
}

signed main(){
    ll t;cin>>t;
    while(t--) solve();
}