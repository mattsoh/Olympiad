#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int maxn = 10;
const int maxp = 1e6+10;
vector<pair<int,bool>> adj[maxn];
vector<string> perms;
bool vis[maxn];
set<int>chosen;
set<int>deleted;
int rooms = -1;
void a(){
    string plan;cin>>plan;
    int p,q;cin>>p>>q;
    rooms = plan.length() + 2;
    for (auto i:plan){
        int ri = i - 65;
        for (int j = 0;j<rooms;j++){
            if (j != ri && chosen.find(j) == chosen.end() && (plan.find((char)(j+65)) == string::npos || deleted.find(j) != deleted.end())){
                chosen.insert(j);
                deleted.insert(ri);
                adj[ri].push_back({j,0});
                adj[j].push_back({ri,0});
                break;
            }
        }
        
    }
    vector<int> un;
    for (int i = 0;i<rooms;i++){
        if (chosen.find(i) == chosen.end()){
            un.push_back(i);
        }
    }
    adj[un[0]].push_back({un[1],0});
    adj[un[1]].push_back({un[0],0});
    for (int i = 0;i<rooms;i++){
        sort(adj[i].begin(),adj[i].end());
        for (auto j:adj[i]) cout<<(char) (j.fi+65);
        cout<<endl;
    }
    int curr = 0;
    for (int i = 0;i<p;i++){
        vis[curr] = 1-vis[curr];
        if (vis[0]){
            adj[curr][0].se = 1-adj[curr][0].se;
            curr = adj[curr][0].fi;
        }else {
            for (int j = 0;j<adj[curr].size();j++){
                if (adj[curr][j].se == 1){
                    if (j == adj[curr].size() - 1) {
                        adj[curr][j].se = 1 - adj[curr][j].se;
                        curr = adj[curr][j].fi;
                    }
                    else {
                        adj[curr][j+1].se = 1 - adj[curr][j+1].se;
                        curr = adj[curr][j+1].fi;
                    }
                }
            }
        }
    }
    cout<<(char) (curr+65);
    for (int i = p;i<q;i++){
        vis[curr] = 1-vis[curr];
        if (vis[0]){
            adj[curr][0].se = 1-adj[curr][0].se;
            curr = adj[curr][0].fi;
        }else {
            for (int j = 0;j<adj[curr].size();j++){
                if (adj[curr][j].se == 1){
                    if (j == adj[curr].size() - 1) {
                        adj[curr][j].se = 1 - adj[curr][j].se;
                        curr = adj[curr][j].fi;
                    }
                    else {
                        adj[curr][j+1].se = 1 - adj[curr][j+1].se;
                        curr = adj[curr][j+1].fi;
                    }
                }
            }
        }
    }
    cout<<(char) (curr+65)<<endl;
}

void gen(string current, int length) {
    if (current.size() == length) {
        perms.push_back(current);
        return;
    }
    for (char c :"ABCDEF") {
        if (c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F') gen(current + c, length);
    }
}
int main(){
    int ccount = 0;
    perms.clear();
    gen("",6);
//     for (const auto& str : perms) {
//     // cout << "'" << str << "'\n";
//     // cout<<str.size()<<endl;
// }
    for (auto plan: perms){
        
        deleted.clear();
        chosen.clear();
        // cout<<plan.size()<<plan[0]<<plan[1]<<plan[2]<<plan[3]<<plan[4]<<plan[5]<<'e'<<endl;
        map<string,bool> inn = {{"AB", 0}, {"BD", 0}, {"CG", 0}, {"DH",0}};
        // memset(inn,0,sizeof(inn));
        rooms = plan.length() + 2;
        bool cont = true;
        for (auto i:plan){
            if (i ==' ') {
                cont = false; break;
            }
            int ri = i - 65;
            for (int j = 0;j<rooms;j++){
                if (j != ri && chosen.find(j) == chosen.end() && (plan.find((char)(j+65)) == string::npos || deleted.find(j) != deleted.end())){
                    chosen.insert(j);
                    deleted.insert(ri);
                    string tt;
                    if (j < ri){
                        tt = (char)(j+65)+i;
                    }else tt = i+(char)(j+65);
                    if (inn.count(tt)) inn[tt] = true;
                    // break;
                }
            }
            
        }
        if (!cont) continue;
        // vector<int> un;
        // for (int i = 0;i<rooms;i++){
        //     if (chosen.find(i) == chosen.end()){
        //         un.push_back(i);
        //     }
        // }
        // string tt;
        // if (un[0] < un[1]){
        //     tt = (char)(un[0]+65)+(char)(un[1]+65);
        // }else tt = (char)(un[1]+65)+(char)(un[0]+65);
        // if (inn.count(tt)) inn[tt] = true;
        // adj[un[0]].push_back({un[1],0});
        // adj[un[1]].push_back({un[0],0});
        // bool poss = true;
        // for (auto qq: inn){
        //     if (qq.se == 0){
        //         poss = false;
        //         break;
        //     }
        // }
        // if (!poss) continue;
        // ccount++;

    }
    cout<<ccount<<endl;
}