#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int maxn = 24;
struct swit {
    pair<int,bool> nxt; // point, dir
    pair<int,bool> curve[2]; // point, dir
    bool flip;
    bool right;
};
bool flip[maxn];
swit switches[maxn] = {
    {{3, 1}, {{4, 1}, {5, 1}}, false, false}, 
    {{2, 1}, {{6, 1}, {7, 1}}, false, false},
    {{1, 1}, {{8, 1}, {9, 1}}, false, false},
    {{0, 1}, {{10, 1}, {11, 1}}, false, false},

    {{0, 0}, {{12, 0}, {13, 0}}, false, false},
    {{0, 0}, {{13, 0}, {14, 0}}, false, false},
    {{1, 0}, {{14, 0}, {15, 0}}, false, false},
    {{1, 0}, {{15, 0}, {16, 0}}, false, false},
    {{2, 0}, {{16, 0}, {17, 0}}, false, false},
    {{2, 0}, {{17, 0}, {18, 0}}, false, false},
    {{3, 0}, {{18, 0}, {19, 0}}, false, false},
    {{3, 0}, {{19, 0}, {12, 0}}, false, false},

    {{20, 0}, {{11, 0}, {4, 0}}, false, false},
    {{20, 0}, {{4, 0}, {5, 0}}, false, false},
    {{21, 0}, {{5, 0}, {6, 0}}, false, false},
    {{21, 0}, {{6, 0}, {7, 0}}, false, false},
    {{22, 0}, {{7, 0}, {8, 0}}, false, false},
    {{22, 0}, {{8, 0}, {9, 0}}, false, false},
    {{23, 0}, {{9, 0}, {10, 0}}, false, false},
    {{23, 0}, {{10, 0}, {11, 0}}, false, false},

    {{21, 1}, {{12, 1}, {13, 1}}, false, false}, 
    {{20, 1}, {{14, 1}, {15, 1}}, false, false},
    {{23, 1}, {{16, 1}, {17, 1}}, false, false},
    {{22, 1}, {{18, 1}, {19, 1}}, false, false}
};
int main(){
    string ff; cin>>ff;
    for (auto i:ff){
        switches[i-'A'].flip = true;
    }
    string start;cin>>start;
    pair<int,int> fst = {start[0]- 'A', start[1] - 'A'};
    pair<int,bool> curr, prev;
    if (switches[fst.fi].nxt.fi == fst.se){
        prev = {fst.fi, 0};
    } else {
        prev = {fst.fi, 1};
    }
    if (switches[fst.se].nxt.fi == fst.fi){
        curr = {fst.se, 1};
    } else {
        curr = {fst.se, 0};
    }
    
    int points;cin>>points;
    for (int i = 0;i<points;i++){
        pair<int,bool> nxt;
        cout<<(char)(curr.fi+ 'A')<<endl;
        if (curr.se == 0){
            nxt = switches[curr.fi].nxt;
        } else {
            nxt = switches[curr.fi].curve[switches[curr.fi].right];
        }
        if (switches[prev.fi].flip) {
            if (prev.se) {
                switches[prev.fi].right = !switches[prev.fi].right;
            }
        }
        if (!switches[curr.fi].flip) {
            if (!curr.se) {
                switches[curr.fi].right = switches[curr.fi].curve[1].fi == prev.fi;
            }
        }
        prev = curr;
        curr = nxt;
    }
    cout<<(char)(prev.fi + 'A')<<(char)(curr.fi + 'A')<<endl;
}