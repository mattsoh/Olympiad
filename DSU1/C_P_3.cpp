#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int maxn = 1e5 + 10;
vector<pair<int,pair<int,int>>> eq;
int par[maxn],s[maxn], ans[maxn];
int find(int x){
    if (x == par[x]){
        return x;
    }
    return par[x] = find(par[x]);
}
void connect(int x, int y){
    int rootX = find(x),rootY = find(y);
    if (rootX != rootY){
        if (s[rootX] < s[rootY]){
            swap(rootX, rootY);
        }
        par[rootY] = rootX;
        s[rootX] += s[rootY];
    }
}
int main(){
    if (fopen("mootube.in", "r")){
        freopen("mootube.in", "r", stdin);
        freopen("mootube.out", "w", stdout);
    }

    int n,q;cin>>n>>q;
    for (int i = 0;i<n-1; i++) {
        int p,q,r;
        cin>>p>>q>>r;
        eq.push_back({r,{p,q}});
        
    }
    for (int i = 1;i<=n;i++){
        par[i] = i;
        s[i] = 1;
    }
    for (int i = 1;i<=q;i++){
        int k,v;cin>>k>>v;
        eq.push_back({k,{-i,v}});
    }
    sort(eq.rbegin(),eq.rend());
    for (int i = 0;i<eq.size();i++){
        if (eq[i].se.fi < 0){
            ans[-eq[i].se.fi] = s[find(eq[i].se.se)]-1;
        }else{
            connect(eq[i].se.fi, eq[i].se.se);
        }
        
    }
    for (int i = 1;i<=q;i++){
        cout<<ans[i]<<endl;
    }
}