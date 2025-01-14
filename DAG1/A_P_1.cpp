// Dfs n times

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int visited[maxn];
vector<int> adj[maxn], ans;
stack<int> st;
void dfs(int x){
    visited[x] = 1;
    st.push(x);
    for (int i:adj[x]){
        if (visited[i] == 0){
            dfs(i);
        }else if (visited[i] == 1){
            ans.push_back(i);
            while (true){
                ans.push_back(st.top());
                if (st.top() == i)break;
                st.pop();
            }
            cout<<ans.size()<<endl;
            for (int j = ans.size()-1;j>=0;j--){
                cout<<ans[j]<<" ";
            }
            exit(0);
            return;
        }
    }
    visited[x] = 2;
    st.pop();
    return;
}
int main(){
    int n,m;cin>>n>>m;
    for (int i = 0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
    }
    for (int i = 0;i<n;i++){
        dfs(i);
    }
    cout<<"IMPOSSIBLE";
}