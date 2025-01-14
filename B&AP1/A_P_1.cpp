#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
vector<ll> adj[maxn], sccadj[maxn]; 
ll low[maxn], num[maxn], scc[maxn], par[maxn], cnt = 0, sccNo = 0;
stack<ll> st;
void dfs(ll u){
    cnt++;
    low[u] = cnt;
    num[u] = cnt;
    st.push(u);
    for (auto i: adj[u]){
        if (scc[i] == 0){
            if (num[i] == 0){
                dfs(i);
                low[u] = min(low[u], low[i]);
            }else{
                low[u] = min(low[u], num[i]); 
            }   
        }
    }
    if (num[u] == low[u]){
        sccNo++;
        while (st.top() != u){
            scc[st.top()] = sccNo;
            st.pop();
        }
        scc[u] = sccNo;
        st.pop();
    }
}
int main(){
    while (true){
        ll n,m;cin>>n>>m;
        // cout<<n<<m<<endl;
        if (n == 0 && m == 0 ) break;
        for (ll i = 1;i<=n;i++) adj[i].clear();
        memset(low, 0, sizeof(low));
        memset(num, 0, sizeof(num));
        while (!st.empty()) st.pop();
        sccNo = 0;
        for (ll i = 0;i<m;i++){
            ll a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (ll i = 1;i<=n;i++){
            dfs(i);
        }
        int vul = 0;
        cout<<"Helo"<<endl;
        cout<<sccNo<<endl;
        for (ll i = 0;i<=n;i++){
            for (auto j:adj[i]){
                if (scc[i] != scc[j]){
                    sccadj[scc[i]].push_back(scc[j]);
                    sccadj[scc[j]].push_back(scc[i]);
                }   
            }
        }
        cout<<vul<<endl;
    }
}