#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
void solve(){
    ll n,d; cin>>n>>d;
    cout<<1<<' ';
    if (n>=3 || d%3==0){
        cout<<3<<' ';
    }
    if (d %5 == 0){
        cout<<5<<' ';
    }
    if (n>=3|| d % 7 == 0){
        cout<<7<<' ';
    }
    if (d == 9 ||n >= 6 || (n >= 3 && d % 3 == 0)){
        cout<<9<<' ';
    }
    cout<<endl;
}
signed main(){
    ll t;cin>>t;
    while (t--) solve();
}