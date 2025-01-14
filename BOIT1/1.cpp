#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxf = 100;
ll fib[maxf];
bool z(ll i){
    ll cnt = 50;
    ll sum = 0;
    while (sum < i){
        cnt --;
        if (fib[cnt] + sum <= i){
            if (fib[cnt] ==  701408733 ) return false;
            sum += fib[cnt];
        }
    }
    return true;
    // for (auto j:nums)cout<<j<<' ';
    // cout<<endl;
}
int main(){
    ll cntt = 0;
    ll a = 1, b = 2, cnt = 2;
    fib[0] = a;fib[1] = b;
    while (a+b <= 5000000000){
        fib[cnt] = a+b;
        a = b;
        b = fib[cnt];
        // cout<<fib[cnt]<<endl;
        cnt++;
    }
    for (ll i = 1000000000; i<= 5000000000;i++){
        if (i%10000000 == 0)cout<<i<<endl;
        if (z(i)) cntt++;
    }
    cout<<cntt<<endl;
}