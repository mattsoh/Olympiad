#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int parent[maxn], s[maxn], maxx = 0, comp, maxS = 1;
int find(int x){
    if (parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}
int main(){
    int n,m;cin>>n>>m;
    for (int i = 1;i<=n;i++){
        parent[i] = i;
        s[i] = 1;
    }
    comp = n;
    for (int i = 0;i<m;i++){
        int x,y;cin>>x>>y;
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY){
            if (s[rootX] < s[rootY]){
                swap(rootX, rootY);
            }
            comp--;
            parent[rootY] = rootX;
            s[rootX]+=s[rootY];
            maxS = max(s[rootX], maxS);
        }
        cout<<comp<<' '<<maxS<<endl;
    }
}