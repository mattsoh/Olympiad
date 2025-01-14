#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100000;
ll a[maxn], st[4*maxn];
void update(ll id, ll i, ll v, ll left, ll right){
    // cout<<i<<v<<left<<right<<endl;
    if (i < left || i > right) return;
    if (left == right){
        st[id] = v;
        return;
    }
    ll mid = (left+right)/2;
    update(id*2, i, v, left, mid);
    update(id*2+1, i, v, mid+1, right); 
    st[id] = max(st[id*2],st[id*2+1]);
}
ll walk(ll id, ll left, ll right, ll x, ll l){
    if (st[id] < x) return -1;
    if (left == right) return left;
    ll mid = (left+right)/2;
    if (mid < l) return walk(id*2+1, mid+1, right,x, l);
    ll val = walk(id*2, left, mid, x,l);
    if (val == -1) return walk(id*2+1, mid+1, right, x,l);
    return val;
}
int main(){
    ll n,m;cin>>n>>m;
    for (ll i = 1;i<=n;i++){
        ll a;cin>>a;
        update(1,i,a,1,n);

    }
    for (ll i = 0;i<m;i++){
        ll a;cin>>a;
        if (a==1){
            ll k,v;cin>>k>>v;
            update(1, k+1, v, 1, n);
        }else{
            ll x,l;cin>>x>>l;
            ll o = walk(1,1,n,x,l+1);
            if (o < 0) cout<< -1;
            else cout << o-1;
            cout<<endl;
        }
    }
}