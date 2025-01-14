#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
const int maxn = 1e12 + 10;
map<array<ll, 4>, ll> dp; // array of 4 for a,b,c,d
set<array<ll,4>>vis;
int main(){
    ll a,b,c,d,n;cin>>a>>b>>c>>d>>n;
    ll len = a+b+c+d;
    queue<array<ll,4>> q;
    q.push({0,0,0,0});
    dp[{0,0,0,0}] = 1;

    while (!q.empty()){
        auto nxt = q.front();q.pop();
        if (vis.find(nxt) != vis.end()) continue;
        ll sum = nxt[0]+nxt[1]+nxt[2]+nxt[3];
        if (sum >= len || nxt[0] > a || nxt[1] > b || nxt[2] > c || nxt[3] > d) continue;
        for (int i = 0;i<4;i++){
            array<ll,4> poss = nxt;
            poss[i]++;
            
            if (sum+1 >= len || poss[0] > a || poss[1] > b || poss[2] > c || poss[3] > d) continue;
            dp[poss] += dp[nxt];
            q.push(poss);
        }
        vis.insert(nxt);
    }
    array<ll,4> init = {a,b,c,d};
    string ans = "";
    for (int i = len-1;i>=0;i--){
        int cnt = 0;
        for (int j = 0;j<=4;j++){
            array<ll,4> poss = init;
            if (poss[j] == 0)continue;
            poss[j]--;
            if (dp[poss] < n) {
                n -= dp[poss];
                // init = poss;
            }else {
                cnt = j; break;
            };
        }
        init[cnt]--;
        ans += cnt+'A';
    }
    cout<<ans<<endl;
}