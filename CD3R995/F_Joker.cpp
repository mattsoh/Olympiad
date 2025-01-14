#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
void solve(){
    ll n, m, q;
    cin >> n >> m >> q;
    ll min_pos = m, max_pos = m;
    vector<pair<ll, ll>> ranges;
    ranges.push_back({m,m});
    for(ll i = 0; i < q; i++){
        ll mv;
        cin >> mv;
        vector<pair<ll, ll>> nxt;
        ll prev = 0;
        bool movej = false;
        for (auto j: ranges){
            ll cnt = 0;
            if (j.fi <= mv && mv <= j.se){
                nxt.push_back({1,1});
                if (n != 1) nxt.push_back({n,n});
                if (j.fi < mv) nxt.push_back({j.fi, mv-1});
                if (mv < j.se) nxt.push_back({mv+1, j.se});
                prev = max(1LL, prev);
                cnt += j.se - max(j.fi, prev) + 1;
                movej = true;
            } else if (mv < j.fi){
                nxt.push_back({j.fi-1, j.se});
                cnt += max(j.se, prev) - max(j.fi-1, prev);
                prev = max(prev, j.se);
                if (movej && j.se == n) cnt--;
            } else{
                nxt.push_back({j.fi, j.se+1});
                cnt += max(j.se+1, prev) - max(j.fi, prev);
                if (movej && j.se+1 == n) cnt--;
            }
            cout<<cnt<<" ";
        }
    }
    cout << endl;
}
signed main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    ll t; cin >> t; while(t--) solve();
}