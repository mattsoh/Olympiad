#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+10;
bool primes[maxn];
int main(){
    int n;cin>>n;
    for (int i = 0;i<=n;i++) primes[i] = true;
    for (int i = 2; i<= sqrt(n);i++){
        if (primes[i]) {
            for (int j = i+i; j <= n;j+=i){
                primes[j] = false;
            }
        }
    }
    int cnt = 1;
    for (int i = 2;i<=n;i++){
        if (n%i == 0)cnt*=i;
        while (n%i == 0){
            n/=i;
        }
    }
    cout<<cnt<<endl;
}