#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n;cin>>n;
    ll mod = 0, summ = 0, summmod = 0;
    ll minn = 0, maxx = 0, minnmod = 0, maxxmod = 0, minnrev = 0, maxxrev = 0, minnrevmod = 0, maxxrevmod = 0;
    for (ll i = 0; i < n; i++){
        ll nxt; cin>>nxt;
        if (nxt != -1 && nxt != 1){
            mod = nxt;
            minnrevmod = minnrev;
            maxxrevmod = maxxrev;
            minnmod = summ - maxxrevmod;
            maxxmod = summ;
            minnrev = 0;
            maxxrev = 0;
            summmod = summ;
            summ = 0;
            // continue;
        }else{
            summ += nxt;
            summmod += nxt;
        }
        minnrev = min(minnrev, summ);
        maxxrev = max(maxxrev, summ);
        minnrevmod = min(minnrevmod, summmod);
        maxxrevmod = max(maxxrevmod, summmod);
        maxx = max(maxx, summ - minnrev);
        minn = min(minn, summ - maxxrev);
        if (mod != 0){

            maxxmod = max(maxxmod, summmod - minnrevmod);
            minnmod = min(minnmod, summmod - maxxrevmod);
        }
        // cout<<summmod<<' '<<minnmod<<' '<<maxxmod<<' '<<minnrevmod<<' '<<maxxrevmod<<endl;
    }
    // cout<<minn<<' '<<maxx<<' '<<minnmod<<' '<<maxxrevmod<<endl;
    set<ll> s;
    for (ll i = minn; i <= maxx; i++){
        s.insert(i);
    }
    for (ll i = minnmod; i <= maxxmod; i++){
        s.insert(i+mod);
    }
    cout<<s.size()<<endl;
    for (auto i:s){
        cout<<i<<' ';
    }
    cout<<endl;
}
signed main(){
    ll t;cin>>t;
    while (t--) solve();
}