#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
vector<int> dirs[2] = {{-6,1,6,-1},{-6, -1, 6, 1}};
map<pair<int, int>, int> edges;
char grid[5][5];
int add_edge(int pos, int p){
    bool changed = false;
    while (!changed){
        pos = (pos-1)%36+1;
        for (auto dir:dirs[p]){
            if ((pos%6==0 && dir == 1) ||pos%6==1 && dir == -1 ||
            pos+dir <= 0 || pos + dir > 36) continue;
            if (edges[{pos,pos+dir }] == 0){
                edges[{pos, pos+dir}] = p+1;
                edges[{pos+dir, pos}] = p+1;
                changed = true;
                break;
            }
        }
        if (!changed)pos++;
        pos = (pos-1)%36+1;
    }
    return pos;
}
bool block(int x){
    if (x>30 || x%6==0) return false;
    if (edges[{x,x+1}] != 0 && edges[{x,x+6}] != 0 && edges[{x+1,x+7}] != 0 && edges[{x+6,x+7}] != 0){
        return true;
    }
    return false;
}
bool square(int pos, int p){
    bool check = false;
    for (auto sq: {-7, -6, -1, 0}){
        int neww = sq+pos;
        if (block(neww)){
            if (grid[(neww-1)/6+1][(neww-1)%6+1] != '*') continue;
            if (p == 0) grid[(neww-1)/6+1][(neww-1)%6+1] = 'X';
            else grid[(neww-1)/6+1][(neww-1)%6+1] = 'O';
            check = true;
        }
    }
    return check;
}
int main(){
    int p1, m1, p2, m2, t;cin>>p1>>m1>>p2>>m2>>t;
    int player = 0;
    for (int i = 1;i<=5;i++){
        for (int j = 1;j<=5;j++){
            grid[i][j] = '*';
        }
    }
    for (int i = 0;i<t;i++){
        if (player == 0){
            p1 += m1;
            p1 = add_edge(p1, 0);
            if (!square(p1, 0)) player = 1;
        } else {
            p2 += m2;
            p2 = add_edge(p2, 1);
            if (!square(p2, 1)) player = 0;
            
        }
    }
    int xsq = 0, osq = 0;
    for (int i = 1;i<=5;i++){
        for (int j = 1;j<=5;j++){
            cout<<grid[i][j]<<' ';
            if (grid[i][j] == 'X') xsq++;
            else if (grid[i][j] == 'O')osq++;
        }
        cout<<endl;
    }
    cout<<xsq<<' '<<osq<<endl;
}