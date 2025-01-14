    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    void solve(){
        ll n,a,b;cin>>n>>a>>b;
        if (abs(a-b)%2==1){
            cout<<"NO"<<endl;
        } else cout<<"YES"<<endl;
    }
    signed main(){
        ll t;cin>>t;
        while (t--) solve();
    }