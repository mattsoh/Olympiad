#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
string str;
int dp[maxn][maxn];
void calc(int s, int len){
    if (dp[s][len] != 0) return;
    if (len == 0){
        dp[s][0] = 0;
        return;
    }
    else if (len <= 1) {
        dp[s][1] = 1;
        return;
    }
    
    int ways = 1; 
    for (int i = 1;i<=len/2;i++){
        if (str.substr(s,i) == str.substr(s+len-i, i)){
            if (i == len-i){
                    ways += 1;
            }
            else{
                calc(s+i,len-i*2);
                ways += dp[s+i][len-i*2];
            }
        }
    }
    dp[s][len] = ways;
}
int main(){
    cin>>str;
    int ways = 0;
    queue <pair<int, int>> q;
    calc(0,str.size());
    cout<<dp[0][str.size()] - 1<<endl;
}