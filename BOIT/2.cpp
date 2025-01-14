#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll T(ll i) {
	ll sqrtx = sqrt(i*2);
	for (ll st = max(1ll, sqrtx-5); st <= sqrtx+5;st++){
		if (i > st * (st - 1) / 2 && i <= st * (st + 1) /2) {
			return st;
		}	
	}
}
ll O(ll i) {return  2 * i - 1;}
ll E(ll i) {return 2 * i;}
ll findB(string s){
	
	ll depth = 1;
	ll open = -1;
	for (ll i = s.length()-2;i>=0;i--){
		if (s[i] == '(') depth--;
		else if (s[i] == ')') depth++;
		if (depth == 0){
			open = i;
			break;
		}
	}
	return open;
}

string combine(string L, string R) {
	return R + L + R;
}
string simplifiedString(string s) {
	cout<<s<<endl;
	if (s.length() == 1) return s;
	string simplifiedR;
	ll startR = -1;
	if (s.back() == ')'){
		startR = findB(s);
 		simplifiedR = simplifiedString(s.substr(startR+1, s.length()-startR-2));
		if (startR == 0) return simplifiedR;
	}else{
		startR = s.length()-1;
		simplifiedR = s.back();
	}
	string simplifiedL = simplifiedString(s.substr(0,startR));
	return combine(simplifiedL, simplifiedR);
}
int main(){
	string str; ll i;
	while (cin>>str>>i){
		string simplified = simplifiedString(str);
		cout<<simplified<<endl;
		for (ll c = simplified.length()-1;c>=0;c--){
			if (simplified[c] == 'O') i = O(i);
			if (simplified[c] == 'E') i = E(i);
			if (simplified[c] == 'T') i = T(i);
		}
		cout<<i<<endl;
	}
}
