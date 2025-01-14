#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn =2e5+10;
struct stt{
    ll s4,s7,s47,s74,la;
};
stt st[4*maxn];
string val;
void merge(int id){
    st[id].s4 = st[id*2].s4 + st[id*2+1].s4;
    st[id].s7 = st[id*2].s7 + st[id*2+1].s7;
    st[id].s47 = max(max(st[id*2].s4+st[id*2+1].s7,st[id*2].s47+st[id*2+1].s7),st[id*2].s4+st[id*2+1].s47);
    st[id].s74 = max(max(st[id*2].s7+st[id*2+1].s4,st[id*2].s74+st[id*2+1].s4),st[id*2].s7+st[id*2+1].s74);
    st[id].la = 0;
}
void build(ll id, ll left, ll right){
    if (left == right){
        if (val[left] == '4'){
            st[id].s4 = 1;
            st[id].s7 = 0;
        }else{
            st[id].s4 = 0;
            st[id].s7 = 1;
        }
        st[id].s47 = 1;
        st[id].s74 = 1;
        return;
    }
    ll mid = (left+right)/2;
    build(id*2,left,mid);
    build(id*2+1,mid+1,right);
    merge(id);
}
void updateNode(ll id, ll left, ll right){
    swap(st[id].s4, st[id].s7);
    swap(st[id].s47, st[id].s74);
    st[id].la = 1-st[id].la;
}
void push(ll id, ll left, ll right){
    if (st[id].la == 0 || left == right){
        return;
    }
    ll mid = (left+right)/2;
    updateNode(id*2, left, mid);
    updateNode(id*2+1, mid+1, right);
    st[id].la = 0;
}
stt get(ll id, ll left, ll right, ll l, ll r){
    if (l>right || r<left){
        stt a;
        a.s4 = 0;a.s7 = 0;a.s47=0;a.s74 = 0;
        return a;
    }
    if (l<=left && r>=right){
        return st[id];
    }
    push(id, left, right);
    ll mid = (left+right)/2;
    stt ret;
    ret.s4 = st[id*2].s4 + st[id*2+1].s4;
    ret.s7 = st[id*2].s7 + st[id*2+1].s7;
    ret.s47 = st[id*2].s47 + st[id*2+1].s47;
    ret.s74 = st[id*2].s74 + st[id*2+1].s74;
    ret.la = 0;
    return ret;
}
void updateRange(ll id, ll left, ll right, ll l, ll r){
    if (l > right||r<left){
        return;
    }
    if (l<=left && r>=right){
        updateNode(id,left,right);
        return;
    }
    push(id,left,right); 
    ll mid = (left+right)/2;
    updateRange(id*2, left,mid,l,r);
    updateRange(id*2+1,mid+1,right,l,r);
    merge(id);
}
int main(){
    ll n,m; cin>>n>>m;
    cin>>val;
    build(1,1,n);
    for (ll i = 0;i<m;i++){
        string x;cin>>x;
        // cout<<x<<endl;
        if (x == "switch"){
            ll a,b;cin>>a>>b;
            updateRange(1,1,n,a,b);
        }else{
            stt ret = get(1,1,n,1,n);
            cout<<max(max(ret.s4,ret.s7),ret.s47)<<endl;
        }
    }
}