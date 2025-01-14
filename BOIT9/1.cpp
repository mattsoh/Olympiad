#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5;
int lucky[maxn];
ll a;
void calc(){
    for (ll i = 1;i<=maxn/2-10;i++){
        lucky[i] = 0;
    }
    lucky[1] = 1;
    ll curr = 1;
    while (curr++ < a*2){
        if (lucky[curr] == 2) continue;
        ll rem = 0, idx = 0;
        while (idx++ < a*2) {
            if (lucky[idx] == 2) continue;
            rem++;
            if (rem%(curr*2-1) == 0){
                lucky[idx] = 2;
            }
        }
        lucky[curr] = 1;
    }
    
}
// void partb(){
//     ll c = 0;
//     for(ll i = 0;i<100;i++){
//         if (lucky[i] == 1){
//             // c++;
//             cout<<i*2-1<<' '; // count numbers below 100
//         }
//     }
//     // cout<<c<<endl;
// }
// void partd(){
//     a = 10000000000;
//     calc();
//     // ll c = 0, idx = 0;
//     // while (c < 1000000000){
//     //     idx++;
//     //     if (lucky[idx] == 1) c++;
//     // }
//     // set<pair<ll,ll>> nums;
//     // for (ll i = 2;i<=idx*2-1;i++){
//     //     ll left = (i+1)/2;
//     //     if (i%2 == 0){
//     //         left = i/2+1;
//     //     }
//     //     while (lucky[--left] == 2){}
//     //     // cout<<left*2-1<<' ';
//     //     ll right = (i+1)/2;
//     //     while (lucky[++right] == 2){}
//     //     // cout<<right*2-1<<endl;
//     //     nums.insert({left,right});
//     // }
//     // cout<<nums.size()<<endl;
// }
int main(){
    cin>>a;
    calc();
    ll left = (a+1)/2;
    if (a%2 == 0){
        left = a/2+1;
    }
    while (lucky[--left] == 2){}
    cout<<left*2-1<<' ';
    ll right = (a+1)/2;
    while (lucky[++right] == 2){}
    cout<<right*2-1<<endl;
}