#include <bits/stdc++.h>
using namespace std;
const int maxn = 249;
int dp[maxn][maxn];
int main(){
    int n;cin>>n;
    int vals[n];
    for (int i = 0;i<n;i++){
        cin>>vals[i];
    }
    for (int i = 0;i<n;i++){
        dp[i][i] = 0;
    }
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            if (i == j) continue;
            dp[i][j] = INT_MAX;
        }
    }
}