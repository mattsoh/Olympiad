#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
const ll maxc = 80;
const ll maxch = 30;
ll dp[maxc][maxch];
ll sum[80];
ll score = 0;
int main(){
    string word;cin>>word;
    vector<ll>w;
    ll maxx = 0;
    for (auto i:word){
        score += (ll) i - 64;
        w.push_back((ll) i - 64);
        maxx = max(maxx,(ll)i-64);
    }
    w.push_back(0);
    cout<<score<<endl;
    for (ll i = 0;i<maxc;i++){
        if (i == 0){
            for (ll j = 0;j<maxx;j++){
                dp[i][j] = 0;
            }
        }else{
            for (ll j = 0;j<maxch;j++){
                dp[i][j] = 0;
            }
        }
    }
    ll cs = w[0], idx = 0;
    sum[0] = maxx;
    for (ll i = 1;i<=score;i++){
        if (i > cs){
            idx++;
            cs = w[idx];
        }
        for (ll prev = i-1; prev >= max(0ll,i-26);prev--){
                if (prev == 0)dp[i][i-prev]++;
                else dp[i][i-prev]+=sum[prev] - dp[prev][i-prev];
        }
        for (ll j = 0;j<maxch;j++)sum[i] += dp[i][j];
    }
    ll summ = 0;
    ll pos = 0, curr = score, prev = 0;
    while (curr > 0){
        for (ll i = 0;i<w[pos];i++){
            if (i == prev) continue;
            summ += dp[curr][i];
        }
        prev = w[pos];
        curr -= w[pos];
        pos++;
    }
    cout<<summ+1<<endl;
}