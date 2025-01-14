#include<bits/stdc++.h>
using namespace std;
int parent[10002];
int main(){
    int n;cin>>n;
    vector<int>adj[n];  
    for (int i = 1;i<=n;i++){
        parent[i] = i;
    }
    for (int i = 1;i<=n;i++){
        cin>>parent[i];
    }
    // int temp;
    for (int i = 1;i<=n;i++){
        // cout<<i<<' '<<adj[adj[i]]<<' '<<adj[adj[adj[i]]]<<endl;
        // int con = adj[adj[i]];
        // if (con == i){
        //     continue;
        // }
        int parentI = find(i),parentT=find(temp);
        if (parentI!=parentT){
            parent[parentT] = parentI;
        }
    }
    int count = 0;
    for (int i = 1;i<=n;i++){
        // int con = adj[adj[i]];
        if (parent[i] == i){
            count++;
        }
    }
    cout<<count<<endl;
}