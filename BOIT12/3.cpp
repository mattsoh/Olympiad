#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int maxn = 30;
ll sum[maxn];
ll pow(ll a, ll b) {
    ll res = 1;
    for (ll i = 0; i < b; i++) {
        res *= a;
    }
    return res;
}
int main(){
    ll n;cin>>n;
    ll csum = 0;
    for (ll i = 1;i<=maxn;i++){
        csum += pow(9,i/2);
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
        while (n >= pow(9,len-length/2-length%2)) {
            n -= pow(9,len-length/2-length%2);
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