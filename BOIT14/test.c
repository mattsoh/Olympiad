#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int maxn = 1e9;
ll a[maxn], freq[maxn];
bool used[maxn][maxn];
int main() {
    freopen("PAIR.INP", "r", stdin);
    freopen("PAIR.OUT", "w", stdout);
    ll n,d;cin>>n>>d;
    for (ll i = 0;i<n;i++){
        cin>>a[i];  
    }
    sort(a, a+n);
    for (ll i = 0;i<n;i++){
        for (ll j = n-1;j>i;j--){
            if (!(used[a[i]+a[j]][i] || used[a[i]+a[j]][j])){
                // cout<<i<<' '<<j<<' '<<a[i]<<' '<<a[j]<<endl;
                used[a[i]+a[j]][i] = used[a[i]+a[j]][j] = true;
                freq[a[i]+a[j]]++;
            }
            if (d==1 && !(used[a[i]+a[j]+1][i] || used[a[i]+a[j]+1][j])) {
                used[a[i]+a[j]+1][i] = used[a[i]+a[j]+1][j] = true;
                freq[a[i]+a[j]+1]++;
            }
        }
    }
    ll maxx = 0;
    for (ll i = 1;i<=maxn;i++){
        maxx = max(maxx, freq[i]);
    }
    cout<<maxx<<endl;
}
