#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
int dp[maxn];
int main(){
    char a,b;cin>>a>>b;
    int n;cin>>n;
    dp[1] = a - 'A' + 1;
    dp[2] = b - 'A' + 1;
    for (int i = 3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2] - 1) % 26 + 1;
    }
    cout<<(char)(dp[n] + 'A' - 1)<<endl;
}