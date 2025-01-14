#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,m,k;cin>>n>>m>>k;
    ll dp[n+1][m][m], cost[n][m];
    for (ll i = 0;i<n;i++){
        for (ll j = 0;j<m;j++){
            cin>>cost[i][j];
            for (ll l = 0;l<m;l++){
                dp[i][j][l] = -1;
            }
        }
    }
    for (ll i = 0;i<m;i++){
        dp[0][i][0] = cost[0][i];
    }
    for (ll i = 0;i<n;i++){
        for (ll j = 0;j<m;j++){
            for (ll l = 1;l<m;l++){
                if (j > 0 && dp[i][j-1][l-1] != -1 && (dp[i][j][l] == -1 || dp[i][j-1][l-1] + cost[i][j] > dp[i][j][l])){
                    dp[i][j][l] = dp[i][j-1][l-1] + cost[i][j];
                    cout<<i<<" "<<j<<" "<<l<<" "<<" cfl "<<i<<' '<<j-1<<' '<<l-1<<" nvis "<<dp[i][j][l]<<endl;
                }
                // if (i == 0) continue;
                for (ll p = 0;p<m;p++){
                    if (i>0 && dp[i-1][p][l] != -1 && (dp[i][j][l] == -1 || dp[i-1][p][l] + cost[i][j] > dp[i][j][l])){
                        dp[i][j][l] = dp[i-1][p][l] + cost[i][j];
                        cout<<i<<" "<<j<<" "<<l<<" "<<" cfu "<<i-1<<' '<<p<<' '<<l<<" nvis "<<dp[i][j][l]<<endl;
                    }
                }
            }
        }
    }
    ll ans = LLONG_MAX;
    for (ll i = 0;i<m;i++){
        if (dp[n-1][m-1][i-1] != -1) ans = min(ans,dp[n-1][m-1][i-1]);
    }
    cout<<ans<<endl;
    // cout<<dp[n-1][m-1][m-1]<<endl;
}
int main(){
    ll t;cin>>t;
    while (t--) solve();
    
}