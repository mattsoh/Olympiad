#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll maxn = 1e5 + 10;
pair<pair<ll,ll>,ll> range[maxn];
ll st[4*maxn], la[4*maxn];
void updateNode(ll id, ll val,ll v) {
    // Apply the value to the current node
    st[id] = max(st[id], v); 
    la[id] = max(la[id], v); // Update the lazy value
    cout << val << " " << st[id] << " " << v << endl;
}

void push(ll id, ll left, ll right) {
    // Push lazy value down to children
    if (la[id] != 0) { 
        ll mid = (left + right) / 2;
        updateNode(id * 2, left, la[id]);       // Update the left child
        updateNode(id * 2 + 1, left, la[id]);  // Update the right child
        la[id] = 0;                      // Reset lazy value for current node
    }
}

void update(ll id, ll left, ll right, ll l, ll r, ll v) {
    if (l > right || r < left) return; // No overlap
    if (l <= left && r >= right) {
        // Current range is fully within the update range
        updateNode(id, left, v); 
        return;
    }
    // Partial overlap: Push lazy values before going deeper
    push(id, left, right);
    ll mid = (left + right) / 2;
    update(id * 2, left, mid, l, r, v);       // Update left child
    update(id * 2 + 1, mid + 1, right, l, r, v); // Update right child
    st[id] = max(st[id * 2], st[id * 2 + 1]); // Update the current node's value
}


int main(){
    ll n;cin>>n;
    ll maxx = 0;
    for (ll i = 0;i<n;i++){
        ll l,r,w;cin>>l>>r>>w;
        range[i] = {{l,r},w};
    }
    sort(range,range+n, [](pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b){
        return a.fi.se < b.fi.se;
    });
    for (ll i = 0;i<n;i++){
        fill(st, st+4*maxn, 0);
        ll r = range[i].fi.se;
        cout<<r<<"risthis"<<endl;
        for (ll j = 0;j<=i;j++){
            ll l1 = range[j].fi.fi;
            // ll r1 = range[j].fi.se;
            ll w1 = range[j].se;
            update(1, 1, r, 1,l1, w1);
        }
        cout<<st[1]<<endl;
        if (r==6){

        }

    }
}