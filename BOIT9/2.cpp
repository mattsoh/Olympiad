#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int maxn = 10;
map<pair<pair<int,int>,int>,bool>vis;
const pair<pair<int,int>,int> match[6][2] = {{{{0,2}, 0}, {{1,3}, 1}}, {{{0,2}, 1}, {{1,3}, 0}}, 
                                            {{{0,3}, 0}, {{1,2}, 1}}, {{{0,1}, 0}, {{2,3}, 1}},
                                            {{{1,2}, 0}, {{0,3}, 1}},{{{2,3},0}, {{0,1}, 1}}}; // pair<pair<dir1,dir2>player>
const pair<pair<int,int>,int> dirs[4] = {{{0,-1}, 2}, {{1,0}, 3}, {{0,1}, 0}, {{-1,0},1}};
map<pair<pair<pair<int,int>,int>, int>,int>adj; // map<pair<pair<loc, dir1>,player>, dir2>;
int cycle(pair<pair<int,int>,int> start, pair<pair<int,int>,int> curr, bool just, int player){
    // int a;cin>>a;
    // cout<<"start: "<<start.fi.fi<<' '<<start.fi.se<<' '<<start.se<<endl;
    // cout<<"curr: "<<curr.fi.fi<<' '<<curr.fi.se<<' '<<curr.se<<endl;
    // cout<<"player: "<<player<<endl;
    // cout<<"countin: "<<adj.count({curr, player})<<endl;
    if (start == curr && !just){
        return 0;
    }
    if (adj.count({curr, player}) == 0){
        return -1;
    }
    vis[{curr.fi, player}] = true;
    int nextdir = adj[{curr,player}];
    pair<pair<int,int>,int> trans = dirs[nextdir];
    pair<pair<int,int>,int> next = {{curr.fi.fi+trans.fi.fi, curr.fi.se+trans.fi.se}, trans.se};
    int res = cycle(start, next, false, player);
    if (res == -1) return -1;
    return res + 1;
    return -1;
}
int main(){
    int n;cin>>n;
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            int type;cin>>type;
            for (auto edge: match[type-1]){
                adj[{{{j,i},edge.fi.fi},edge.se}] = edge.fi.se;
                adj[{{{j,i},edge.fi.se},edge.se}] = edge.fi.fi;
            }
        }
    }
    int red = 0, green = 0;
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            if (!vis[{{i,j}, 0}]){
                for (int dir = 0;dir<4;dir++){
                    int res = cycle({{i,j}, dir}, {{i,j}, dir}, true, 0);
                    if (res != -1){
                        red += res;
                        break;
                    }
                }
            }
            if (!vis[{{i,j}, 1}]){
                for (int dir = 0;dir<4;dir++){
                    int res = cycle({{i,j}, dir}, {{i,j}, dir}, true, 1);
                    if (res != -1){
                        green += res;
                        break;
                    }
                }
            }
        }
    }
    cout<<red<<' '<<green<<endl;
}