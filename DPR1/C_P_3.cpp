#include <bits/stdc++.h>
using namespace std;
int main(){
    int s;cin>>s;
    int n;cin>>n;
    int color[n];
    for (int i = 0;i<n;i++){
        cin>>color[i];
    }
    int dp[n][n];
    for (int len = 2; len <= n; len++) { // iterate by length , use shorter length to update longer length
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1; // ending point of this subarray 
            for (int k = i;k<j;k++){
                if (dp[i][k] == -1 || dp[k+1][j] == -1){
                    continue;
                }
                if (dp[i][k] == dp[k+1][j]){
                    d   p[i][j] = dp[i][k]+1;
                }
            }
        }
    }
}