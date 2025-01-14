#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
map<pair<int,int>, int> grid;
int seq[10];
const pair<int,int> dirs[4] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
void ins(pair<int,int> pos){
    grid[pos]++;
    if (grid[pos] == 4){
        grid[pos] = 0;
        for (auto dir: dirs){
            ins({pos.fi + dir.fi, pos.se+dir.se});
        }
    }
}
int main(){
    int p;cin>>p;
    int s;cin>>s;
    int n;cin>>n;
    for (int i = 0;i<s;i++){
        cin>>seq[i];
    }
    int idx = 0;
    p--;
    for (int i = 0;i<n;i++){
        ins({p/5, p%5});
        p = (p + seq[idx]) % 25;
        idx = (idx + 1) % s;
    }
    for (int i = 0;i<5;i++){
        for (int j = 0;j<5;j++){
            cout<<grid[{i,j}]<< ' ';
        }
        cout<<endl;
    }
}