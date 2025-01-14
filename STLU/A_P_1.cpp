#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn =2e5+10;
ll st[4*maxn], la[4*maxn];
ll val[maxn];
void build(ll id, ll left, ll right){
    if (left == right){
        st[id] = val[left];
        return;
    }
    ll mid = (left+right)/2;
    build(id*2,left,mid);
    build(id*2+1,mid+1,right);
    st[id] = st[id*2]+st[id*2+1];
    
}
void updateNode(ll id, ll left, ll right, ll v){
    st[id] += (right-left+1) * v;
    la[id] += v;
}
void push(ll id, ll left, ll right){
    if (left == right){
        return;
    }
    ll mid = (left+right)/2;
    updateNode(id*2, left, mid, la[id]);
    updateNode(id*2+1, mid+1, right, la[id]);
    la[id] = 0;
}
ll get(ll id, ll left, ll right, ll l, ll r){
    if (l>right || r<left){
        return 0;
    }
    if (l<=left && r>=right){
        return st[id];
    }
    push(id, left, right);
    ll mid = (left+right)/2;
    return get(id*2, left, mid, l, r) + get(id*2+1,mid+1, right,l,r);
}
void updateRange(ll id, ll left, ll right, ll l, ll r, ll v){
    if (l > right||r<left){
        return;
    }
    if (l<=left && r>=right){
        updateNode(id,left,right,v);
        return;
    }
    push(id,left,right); 
    ll mid = (left+right)/2;
    updateRange(id*2, left,mid,l,r,v);
    updateRange(id*2+1,mid+1,right,l,r,v);
    st[id] = st[id*2] + st[id*2+1];
}
int main(){
    ll n,q; cin>>n>>q;
    for (ll i = 1;i<=n;i++){
        cin>>val[i];
    }
    build(1,1,n);
    for (ll i = 0;i<q;i++){
        ll x;cin>>x;
        if (x == 1){
            ll a,b,u;cin>>a>>b>>u;
            updateRange(1,1,n,a,b,u);
        }else{
            ll k;cin>>k;
            cout<<get(1,1,n,k,k)<<endl;
        }
    }
}