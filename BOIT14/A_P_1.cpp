#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll maxn = 23900, maxs = 2e7+5;
ll a[maxn];
unordered_map<ll,ll> freq;
unordered_map<ll, ll> d0freq, sum;
unordered_map<ll, bool> used[maxn];
int main() {
    cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(0);
    if (fopen("PAIR.INP", "r")) {
        freopen("PAIR.INP", "r", stdin);
        freopen("PAIR.OUT", "w", stdout);
    }
    ll n,d;cin>>n>>d;
    ll big = 0;
    for (ll i = 0;i<n;i++){
        cin>>a[i]; 
        big = max(big, a[i]); 
        if (d==0)d0freq[a[i]]++;
    }
    ll maxx = 0;
    if (d==0){
        for (auto i:d0freq){
            sum[i.fi*2] += i.se/2;
            for (auto j:d0freq){
                if (i.fi >= j.fi) continue;
                sum[i.fi+j.fi] += min(i.se,j.se);
            }
        }
        for (auto i:sum){
            maxx = max(i.se, maxx);
        }
        cout<<maxx<<endl;
        return 0;
    }
    sort(a, a+n);   
    for (ll i = 0;i<n;i++){
        for (ll j = n-1;j>i;j--){
            ll sum = a[i]+a[j];
            if (!(used[i][sum] || used[j][sum])){
                used[i][sum] = used[j][sum] = true;
                freq[sum]++;
                maxx = max(maxx, freq[sum]);
            }
            if (!(used[i][sum+1] || used[j][sum+1])) {
                used[i][sum+1] = used[j][sum+1] = true;
                freq[sum+1]++;
                maxx = max(maxx, freq[sum+1]);
            }
        }
    }
    cout<<maxx<<endl;
}
