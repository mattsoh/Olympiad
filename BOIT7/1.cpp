#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
const int m = 9999999;
pair<ll,ll> store[m];
// set<ll> poss;
// void dfs(string s){

// }
int main(){
    string inp;cin>>inp;
    pair<ll,ll>curr = {1,1};
    ll prevl = -1, prevr = -1;
    store[0] = {1,1};
    ll idx = 1;
    for (auto i:inp){
        pair<ll,ll> add = {0,0};
        if (i == 'L') prevl = idx;
        else if (i == 'R')prevr = idx;
        ll l, m, r, s;
        if (prevl == -1) {
            l = 1;
            m = 0;
        } else{
            pair<ll,ll> lft = store[prevl-1];
            l = lft.fi; m = lft.se;
        }
        add.fi += l; add.se += m;
        if (prevr == -1){
            r = 0;
            s = 1;
        } else{
            pair<ll,ll> ri = store[prevr-1];
            r = ri.fi; s = ri.se;
        }
        add.fi += r; add.se += s;
        store[idx++] = add;
    }
    pair<ll,ll> res = store[inp.size()];
    for (ll i = 2;i<=sqrt(max(res.fi,res.se));i++){
        while (res.fi % i == 0 && res.se % i == 0){
            res.fi /= i;
            res.se /= i;
        }
    }
    cout<<res.fi<<" / "<<res.se<<endl;
}