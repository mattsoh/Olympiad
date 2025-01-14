#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef unsigned long long ull;
ull countLen(ull n) {
	ull cnt = 0; 
	while (n > 0){
		cnt++;
		n = n / 10; 
	}
	return cnt;
}
ull F(ll x){
	ll count = 0;
	ll xLen = countLen(x);
	ll currPower = 1;
	for (ll digit = 1;digit<=xLen;digit++){
		if (digit == xLen){
			count += digit * (x - currPower + 1);
		}else{
			
			count += digit * (currPower*9);
			currPower *= 10;
		}
	}
	return count;
}


ull digit(ll n, ll i){
    ull l = n, h = 7e17;
    while (l <= h){
	    ull mid = (l + h)/2; 
	    ull x = mid;
	    if (F(x) - F(n -1) >= i) {
		    h = mid - 1;
        } else {
            l = mid + 1; 
        } 
    }
    ull p = F(l) - F(n - 1) - i;
    for (ull i = 0;i<p;i++) l/=10; 
    // cout<<l%10;
    return l%10;
    // cout<<l%10<<endl;
}
// ull digit1(){
//     l = 198765432;
//     ull p = 8;
//     for (ull i = 0;i<p;i++) l/=10; 
//     // cout<<l%10;
//     return l%10;
//     // cout<<l%10<<endl;
// }
int main(){
    ull n,i;
    while (cin>>n>>i)cout<<digit(n,i);

}
