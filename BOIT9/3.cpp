#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
const ll maxn = 10000;
ll dp[maxn+2][39]; // len, starting with x
ll totals[maxn];
set<pair<ll,ll> >vis;
int main(){
    ll n;cin>>n;
    dp[0][37] = 1;
    queue<pair<ll,ll> >q;
    q.push({0,37});
    // return 0;
    while (!q.empty()){
        auto curr = q.front();q.pop();
        if (vis.find(curr) != vis.end()) continue;
        ll len = curr.fi;
        if (len == maxn) continue;
        ll last = curr.se;
        for (ll i = last-1;i>0;i--){
            dp[len+1][i] += dp[len][last];
            q.push({len+1,i});
        }
        vis.insert(curr);
    }
    // for (ll i = 0;i<maxn;i++){
    //     for (ll j = 1;j<=37;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    ll last = 0;
    ll c;
    for (ll len = 0; len <= maxn;len++){
        for (ll i = 1;i<=36;i++){
            c+= dp[len][i];
        }
        totals[len] = c;
    }
    totals[0] = 0;
    n--;
    ll prev = 0;
    string ans = "";
    for (ll len = maxn;len>0;len--){
        // cout<<"total"<<len<<' '<<totals[len-1]<<endl;
        if (n < totals[len-1] && prev == 0)continue;
        if (prev == 0)n -= totals[len-1];
        // cout<<"N is now "<<n<<endl;
        // cout<<"prev is now"<<prev<<endl;
        prev++;
        for (ll i = prev;i<37;i++){
            if (n < dp[len][i]) break;
            n -= dp[len][i];
            // cout<<i<<'|'<<dp[len][i]<<' ';
            prev++;
        }
        // cout<<endl;
        ll change = 1;
        // cout<<"Countlen"<<'|'<<prev<<' '<<len<<endl;
        if (prev >= 27) ans += prev - 26 - change + '0';
        else ans += prev-change+'A';
    }
    cout<<ans<<endl;
}