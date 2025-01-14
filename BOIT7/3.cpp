#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxl = 7e7;
ll dp[maxl]; // dp[i] is shortest path from i to p
ll prime[maxl];
// ll ways[maxl]; // part b
bool isPrime(ll p){
    if (prime[p] != -1) return prime[p];
    for (ll i = 2;i<=sqrt(p);i++){
        if (p%i==0){
            prime[p] = 0;
            return false;
        }
    }
    prime[p] = 1;
    return true;
}
int main(){
    ll l,p,q;cin>>l>>p>>q;
    queue<ll> qe;
    for (ll i = 0;i<l;i++) prime[i] = -1;
    dp[p] = 1;
    qe.push(p);
    while (!qe.empty()){
        ll num = qe.front();
        qe.pop();
        for (ll i = 0; i<max(log2(num),log2(l-num));i++){
            ll newl = num - (1<<i);
            if (newl > 1 && isPrime(newl)){
                if (dp[newl] == 0 || dp[num]+1 < dp[newl]){
                    dp[newl] = dp[num] + 1;
                    qe.push(newl);
                }
            }
            ll newh = num + (1<<i);
            if (newh <= l && isPrime(newh)){
                if (dp[newh] == 0 || dp[num]+1 < dp[newh]){
                    dp[newh] = dp[num] + 1;
                    qe.push(newh);
                }
            }
        }
    }
    cout<<dp[q]<<endl;
}
// void b(){
//     ll l,p,q;cin>>l>>p>>q;
//     queue<ll> qe;
//     for (ll i = 0;i<l;i++) prime[i] = -1;
//     dp[p] = 1;
//     ways[p] = 1;
//     qe.push(p);
//     while (!qe.empty()){
//         ll num = qe.front();
//         qe.pop();
//         for (ll i = 0; i<max(log2(num),log2(l-num));i++){
//             ll newl = num - (1<<i);
//             if (newl > 1 && isPrime(newl)){
//                 if (dp[newl] == 0 || dp[num]+1 < dp[newl]){
//                     dp[newl] = dp[num] + 1;
//                     qe.push(newl);
//                 }
//                 ways[newl] += ways[num];
//             }
//             ll newh = num + (1<<i);
//             if (newh <= l && isPrime(newh)){
//                 if (dp[newh] == 0 || dp[num]+1 < dp[newh]){
//                     dp[newh] = dp[num] + 1;
//                     qe.push(newh);
//                 }
//                 ways[newh] += ways[num];
//             }
//         }
//     }
//     for (int i = 2;i<=l;i++)cout<<dp[i]<<' ';
//     cout<<endl;
//     cout<<ways[19]<<endl;
//     cout<<dp[q]<<endl;
// }
// int main(){
//     for (int i = 0;i<=250000;i++)prime[i] = -1;
//     set<pair<ll,ll>>pairs;
//     for (ll i = 2;i<=250000;i++){
//         if (!isPrime(i))continue;
//         for (ll j = 0;j<=18;j++){
//             if (i+(1<<j) <= 250000 && isPrime(i + (1<<j))){
//                 pairs.insert({i,i+(1<<j)});
//             }
//             if (i - (1<<j) >= 2 && isPrime(i- (1<<j))){
//                 pairs.insert({i-(1<<j),i});
//             }
//         }
//     }
//     cout<<pairs.size()<<endl;
// }