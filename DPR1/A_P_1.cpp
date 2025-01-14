#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);
    int n;cin>>n;
    vector<int> dist(n);
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, INT_MAX)));
    for (int i = 0; i < n; i++){
        cin>>dist[i];
    }   
    sort(dist.begin(), dist.end());
    for (int i = 0; i < n; i++){
        dp[i][i][0] = abs(dist[i]) * n;
        dp[i][i][1] = abs(dist[i]) * n;
    }
    for (int i = n-1;i>=0;i--){
        for (int j = i;j<n;j++){
            if (i == j){
                dp[i][j][0] = abs(dist[i]) * n;
                dp[i][j][1] = abs(dist[j]) * n;
            }else{
                int rem = n+i-j;
                dp[i][j][0] = min(dp[i+1][j][0]+(abs(dist[i+1]-dist[i])*rem),dp[i+1][j][1]+(abs(dist[j]-dist[i])*rem));			
                dp[i][j][1] = min(dp[i][j-1][1]+(abs(dist[j-1]-dist[j])*rem),dp[i][j-1][0]+(abs(dist[j]-dist[i])*rem));
            }
        }
    }
    cout<<min(dp[0][n-1][0], dp[0][n-1][1]);
}