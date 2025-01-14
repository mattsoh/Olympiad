#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn =200003,base = 3e18;
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
    st[id] = min(st[id*2],st[id*2+1]);
}
void updateNode(ll id, ll left, ll right, ll v){
    st[id] += v;
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
        return base;
    }
    if (l<=left && r>=right){
        return st[id];
    }
    push(id, left, right);
    ll mid = (left+right)/2;
    return min(get(id*2, left, mid, l, r),get(id*2+1,mid+1, right,l,r));
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
    st[id] = min(st[id*2], st[id*2+1]);
}
int main(){
    ll n; cin>>n;
    for (ll i = 1;i<=n;i++){
        cin>>val[i];
    }
    build(1,1,n);
    int q;cin>>q;
    string s;
    getline(cin,s); 
    for (ll i = 0;i<q;i++){
        string s;
        getline(cin,s);
        int a,b,u;
        if (sscanf(s.data(), "%d%d%d", &a, &b, &u)==3){
            a++;b++;
            if (a>b){
                updateRange(1,1,n,a,n,u);
                updateRange(1,1,n,1,b,u);
            }else{
                updateRange(1,1,n,a,b,u);
            }
           
        }else{
            a++;b++;
            if (a>b){
                cout<<min(get(1,1,n,a,n),get(1,1,n,1,b))<<endl;
            }else{
                cout<<get(1,1,n,a,b)<<endl;
            }
        }
    }
}