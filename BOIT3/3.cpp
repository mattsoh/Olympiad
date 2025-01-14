#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxp = 15;
vector<vector<ll>>plans;
ll dp[maxp][maxp][maxp]; // length x (r), starting on y (p), repeating z times (q)
ll letters[maxp];
int main(){
    ll p,q,r;cin>>p>>q>>r;
    for (ll i = 0;i<=r;i++){
        for (ll j = 0;j<=p;j++){
            for (ll k = 0;k<=q;k++){
                dp[i][j][k] = 0;
            }
        }
    }
    for (ll i = 1;i<=p;i++){
        dp[1][i][1] = 1;
    }
    for (ll i = 1;i<=r;i++){
        for (ll j = 1;j<=p;j++){
            for (ll k = 2; k<=min(q, r-i+1);k++){
                dp[i+k-1][j][k] = dp[i][j][1];
            }
            for (ll k = 1;k<=p;k++){   
                if (k != j){
                    for (ll l = 1;l<=q;l++){
                        dp[i+1][k][1] += dp[i][j][l];
                    }
                }
            }
        }
    }
    ll n;cin>>n;
    for (ll i = 1;i<=r;i++)letters[i]=1;
    ll con = 1;
    for (ll i = r;i>=1;i--){
        for (ll j = 1;j<=p;j++){
            ll cnt = 0;
            for (ll k = 1;k<=q;k++){
                if (letters[i+1] != j || con + k <= q){
                    cnt += dp[i][j][k];
                }
            }
            if (n>cnt){
                n -= cnt;
                letters[i]++;
            }else{
                break;
            }
        }
        if (letters[i] == letters[i+1])con++;
        else con = 1;
    }
    for (ll i = r;i>=1;i--){
        cout<<(char)(letters[i]+64);
    }
    cout<<endl;
}