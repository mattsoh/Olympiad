#include <bits/stdc++.h>
using namespace std;
int order[10];
vector<int> curr;
map<string,int> dp; // DP map.
map<string,vector<string>>path;
string alph = "ABCDEFGHIJKLM";
int main(){
    string inp;cin>>inp;
    queue<string> q;
    int count = 0;
    dp.insert({"A",1});
    path.insert({"A", {"A"}});
    q.push("A");
    while (!q.empty()){
        string x = q.front();
        q.pop();
        cout<<x<<endl;
        if (x.length() < inp.length()){
            string add = x + alph[x.length()];
            if (dp.find(add) == dp.end()){
                q.push(add);
                dp[add] = dp[x] + 1;
                dp[add] = min(dp[add],dp[x]+1);
                path.insert(add,{path[x]});
                path[add][0].push_back(add);
            }
            if (dp[x] + 1 > dp[add]){
                path.insert(add,{path[x]});
                path[add][0].push_back(add);
                dp[add] = dp[x]+1;
            } else if (dp[x] + 1 == dp[add]){
                path[x].append(add);
                path[add].push_back(path[x]);
                path[x].pop_back();
            }
        }
        
        if (x.length() > 1){
            string sw;
            sw += x[1];
            sw += x[0];
            sw +=  x.substr(2);
            if (dp.find(sw) == dp.end()){
                q.push(sw);
                dp[sw] = dp[x] + 1;
                dp[sw] = min(dp[sw],dp[x]+1);
                path.insert(sw,{path[x]});
                path[sw][0].push_back(sw);
            }
            if (dp[x] + 1 > dp[sw]){
                path.insert(sw,{path[x]});
                path[sw][0].push_back(sw);
                dp[sw] = dp[x]+1;
            } else if (dp[x] + 1 == dp[sw]){
                path[x].append(sw);
                path[sw].push_back(path[x]);
                path[x].pop_back();
            }
            string rep = x.substr(1) + x[0];
            if (dp.find(rep) == dp.end()){
                q.push(rep);
                dp[rep] = dp[x] + 1;
                dp[rep] = min(dp[rep],dp[x]+1);
                path.insert(rep,{path[x]});
                path[rep][0].push_back(rep);
            }
            if (dp[x] + 1 > dp[rep]){
                path.insert(rep,{path[x]});
                path[rep][0].push_back(rep);
                dp[rep] = dp[x]+1;
            } else if (dp[x] + 1 == dp[rep]){
                path[x].append(rep);
                path[rep].push_back(path[x]);
                path[x].pop_back();
            }
        }
        
    }
    cout<<dp[inp]<<endl;
    cout<<path[inp].length()<<endl;
}
