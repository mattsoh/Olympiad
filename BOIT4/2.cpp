#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
deque<pair<int,int>> trail;
int main(){
    int t;cin>>t;
    string i;cin>>i;
    int m;cin>>m;
    int loc[2] = {0,0};
    int dir = 0;
    trail.push_back({0,0});
    for (int move = 0;move<m;move++){
        if (i[move%i.size()] == 'R'){
            dir = (dir+1)%4;
        }else if (i[move%i.size()] == 'L'){
            dir = (dir+3)%4;
        }
        auto prevdir = dir;
        bool np = false;
        int c = 0;
        while (find(trail.begin(),trail.end(),make_pair(loc[0]+dirs[dir][0],loc[1]+dirs[dir][1])) != trail.end()){
            dir = (dir+1)%4;
            c++;
            if (c >= 4){
                np = true;
                cout<<move<<endl;
                break;
            }
        }
        if (np)break;
        loc[0] += dirs[dir][0];
        loc[1] += dirs[dir][1];
        if (trail.size() >= t)trail.pop_front();
        trail.push_back({loc[0],loc[1]});
    }
    cout<<loc[0]<<' '<<loc[1]<<endl;
}