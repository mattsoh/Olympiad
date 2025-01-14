#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int maxn = 100002;
int dp[maxn][4];
map<int,vector<pair<int,int>>mp;
int main(){
    int n, shortest;cin>>n;
    pair<int,int> l,b,fences[n];cin>>l.fi>>l.se>>b.fi>>b.se;
    for (int i = 0;i<n;i++){
        int a,b;
        cin>>a>>b;
        fences[i] = {a,b};
        mp[a].push_back({b,i});
        for (int j = 0;j<4;j++){
            dp[i][j] = -1;
        }
    }
    queue<pair<pair<int,int>,int>>tovisit;
    tovisit.push({l,0});
    tovisit.push({l,1});
    tovisit.push({l,2});
    tovisit.push({l,3}); 
    while (!tovisit.empty()){
        auto u = tovisit.front();tovisit.pop();
        pair<int,int> x = u.fi;
        int dir = u.se;
        if (x == b){
            continue;
        }
        for (auto i:mp[x]){
            int next = i.fi, mirror = i.se;
            
        }
        for (auto i:fences){
            if (i == x){
                continue;
            }
            if (i.fi == x.fi)
        }
    }
}