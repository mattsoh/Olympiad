#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
set<vector<int>> visited;
int maxd = 0;
int main(){
    string b;
    do{
    // int a;cin>>a;
    // string b;cin>>b;
    int n = 0;
    vector<int> serial;
    for (auto i:b)serial.push_back( (int) i - '0');
    queue<pair<vector<int>,int>> q;
    q.push({serial,0});
    visited.insert(serial);
    while (!q.empty()){
        vector<int> curr = q.front().fi;
        for (auto i:curr)cout<<i;
        int depth = q.front().se;
        // cout<<' '<<depth<<endl;
        cout<<endl;
        q.pop();
        for (int i = 0;i<curr.size()-1;i++){
            vector<int> next = curr;
            if ((i > 0 && (next[i-1] > next[i] && next[i-1]<next[i+1]) || (next[i-1] < next[i] && next[i-1]>next[i+1])) ||
                (i<next.size()-1 && (next[i+2] > next[i] && next[i+2] < next[i+1]) || (next[i+2] < next[i] && next[i+2]>next[i+1]))){
            swap(next[i],next[i+1]);
            if (visited.count(next) == 0){
                visited.insert(next);
                q.push({next,depth+1});
                maxd = max(maxd,depth+1);
            }
        }}
    }}
    while (next_permutation(b.begin(),b.end()));
    cout<<maxd<<endl;
}