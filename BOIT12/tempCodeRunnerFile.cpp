#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 30;
ll dp[maxn], sum[maxn];
int main(){
    ll n;cin>>n;
    dp[0] = 1;
    for (ll i = 1;i<=maxn;i++){
        if (i%2 == 0) dp[i] = dp[i-1] * 9;
        else dp[i] = dp[i-1];

    }
    ll csum = 0;
    for (ll i = 1;i<=maxn;i++){
        csum += dp[i];
        sum[i] = csum;
    }
    ll length = 1;
    vector<ll> ans;
    n--;
    for (ll len = maxn-1; len >= 1; len--) {
        if (n < sum[len] && length == 1) {
            continue;
        }
        if (length == 1) {
            length = len+1;
            n -= sum[len];
        }  else if (len * 2 < length) break;
        ll c = 1;
        while (n >= dp[len-1]) {
            n -= dp[len-1];
            c++;
        }
        ans.push_back(c);
    }
    for (auto i:ans){
        cout<<i;
    }
    if (length % 2 == 1) cout<<5;
    reverse(ans.begin(), ans.end());
    for (auto i: ans) {
        cout<<10-i;
    }
    cout<<endl;
}