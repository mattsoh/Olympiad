#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll l, r, G;
        cin >> l >> r >> G;
        ll x_min = (l + G - 1) / G;
        ll y_max = r / G;
        if(x_min > y_max){
            cout << "-1 -1\n";
            continue;
        }
        ll A = G * x_min;
        ll B = G * y_max;
        if(__gcd(x_min, y_max) ==1){
            cout << A << " " << B << "\n";
        }
        else{
            bool found = false;
            for(ll y = y_max; y >= x_min; --y){
                if(__gcd(x_min, y) ==1){
                    B = G * y;
                    found = true;
                    break;
                }
            }
            if(found){
                cout << A << " " << B << "\n";
            }
            else{
                cout << A << " " << A << "\n";
            }
        }
    }
}