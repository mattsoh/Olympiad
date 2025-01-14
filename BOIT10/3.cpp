#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
unordered_set<string> vis;
char offset[2] = {'a', 'A'};
pair<int,int> DIRS[5] = {{0,1}, {1,0}, {-1,0}, {0,-1}, {0,0}};
array<array<int,5>,5> decode(string s){
    array<array<int,5>,5> grid;
    for (int i = 0;i<5;i++){
        for (int j = 0;j<5;j++){
            grid[i][j] = 0;
        }
    }
    for (auto i:s){
        if (i > 95){
            int pos = i - 'a';
            grid[pos/5][pos%5] = 1;
        } else {
            int pos = i - 'A';
            grid[pos/5][pos%5] = 2;
        }
    }
    return grid;
}
string encode (array<array<int,5>,5> grid){
    string fin;
    for (int i =0;i<25;i++){
        // cout<<i/5<<' '<<i%5<<' '<<grid[i/5][i%5]<<' '<<<<endl;s
        if (grid[i/5][i%5] > 0){
            fin += offset[grid[i/5][i%5]-1] + i;
        }
    }
    return fin;
}
bool solved(array<array<int,5>,5> grid){
    for (int i = 0;i<5;i++){
        for (int j = 0;j<5;j++){
            if (grid[i][j] > 0) {
                return false;
            }
        }
    }
    return true;
}
int getBack (char i){
    int r;
    if (i > 95){
            r = i - 'a';
        } else {
            r = i - 'A';
    }
    return r;
}
int main(){
    string str;cin>>str;
    // auto arr = decode(s);
    // for (int i = 0;i<5;i++){
    //     for (int j = 0;j<5;j++){
    //         cout<<arr[i][j];
    //     }
    //     cout<<endl;
    // }
    // cout<<encode(arr)<<endl;
    queue<pair<string,string>> q; // state, prev
    q.push({str, ""});
    while (!q.empty()){
        auto nxt = q.front();q.pop();
        // cout<<nxt.fi<<' '<<nxt.se<<endl;
        // if (nxt.se.size() >= 5) continue;
        auto grid = decode(nxt.fi);
        string prev = nxt.se;
        if (solved(grid)) {
            cout<<prev<<endl;
            return 0;
        }
        // cout<<getBack(prev.back())+1<<endl;
        for (int let = max(getBack(prev.back())+1, 0); let < 25;let++){
            
            for (int press = 1;press <= 2;press++){
                auto tmpgrid = grid;
                for (auto chg: DIRS){
                    pair<int,int> coords = {let/5, let%5};
                    if (!(coords.fi == 0 && chg.fi == -1 || coords.fi == 4 && chg.fi == 1 ||
                    coords.se == 0 && chg.se == -1 || coords.se == 4 && chg.se == 1)){
                        tmpgrid[coords.fi + chg.fi][coords.se + chg.se] = (tmpgrid[coords.fi + chg.fi][coords.se + chg.se]+press)%3;
                    }
                }
                string tmpprev = prev;
                tmpprev += let + offset[press-1];
                string enc_grid = encode(tmpgrid);
                if (vis.find(enc_grid) == vis.end()) {
                    // cout<<(char) (let + offset[press-1])<<"wefw"<<endl;
                    q.push({enc_grid,tmpprev});
                }
            }
        }
        vis.insert(nxt.fi);
    }
    cout<<"IMPOSSIBLE"<<endl;
}