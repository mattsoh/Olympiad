
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2e5+4;
ll st[4*maxn];
ll inp[maxn];
void build(ll indx, ll left, ll right){
    if (left == right){
        st[indx] = inp[left];
    }else{
        ll middle = (left+right)/2;
        build(indx*2, left, middle);
        build(indx*2+1, middle+1, right);
        st[indx] = st[indx*2]^st[indx*2+1];
    }
}   
ll get(ll id, ll left, ll right, ll l, ll r) {
    if (left > r || right < l){
        return 0;
    }
    if (left >= l && right <= r){
        return st[id];
    }
    ll mid = (left+right)/2;
    ll x = get(id*2,left,mid,l,r)^get(id*2+1,mid+1,right,l,r);
    return x; 
}
int main() {
    ll n,q;cin>>n>>q;
    for (ll i = 1; i <= n; i++) {
        cin>>inp[i];
    }
    build(1, 1, n);
    for (ll i = 0; i < q; i++) {
        ll l,r;cin>>l>>r;
        cout<<get(1, 1, n, l, r)<<endl;
    }
}