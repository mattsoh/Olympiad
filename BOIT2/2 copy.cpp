#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int trav[10];
int per = 3;
map<pair<int,int>,int> board;
tuple<int,int,int> poses[10][3];
array<int,3> next_pos(array<int,3> pos[3]) {
    if (pos[1] % 2 == 0) { // on an up triangle
        if (pos[2] == 0) { // left
            if (board.count({pos[0] - 1, pos[1] + 2})) {
                pos[0] = pos[0] - 1; pos[1] = pos[1] + 2; pos[2] = 2;
            } else if (board.count({pos[0] - 1, pos[1] + 3})) {
                pos[0] = pos[0] - 1; pos[1] = pos[1] + 3; pos[2] = 0;
            } else if (board.count({pos[0], pos[1] + 2})) {
                pos[0] = pos[0]; pos[1] = pos[1] + 2; pos[2] = 0;
            } else if (board.count({pos[0], pos[1] + 1})) {
                pos[0] = pos[0]; pos[1] = pos[1] + 1; pos[2] = 1;
            } else {
                pos[0] = pos[0]; pos[1] = pos[1]; pos[2] = 1;
            }
        } else if (pos[2] == 1) { // right
            if (board.count({pos[0] + 1, pos[1]})) {
                pos[0] = pos[0] + 1; pos[1] = pos[1]; pos[2] = 0;
            } else if (board.count({pos[0] + 1, pos[1] - 1})) {
                pos[0] = pos[0] + 1; pos[1] = pos[1] - 1; pos[2] = 1;
            } else if (board.count({pos[0] + 1, pos[1] - 2})) {
                pos[0] = pos[0] + 1; pos[1] = pos[1] - 2; pos[2] = 1;
            } else if (board.count({pos[0], pos[1] - 1})) {
                pos[0] = pos[0]; pos[1] = pos[1] - 1; pos[2] = 2;
            } else {
                pos[0] = pos[0]; pos[1] = pos[1]; pos[2] = 2;
            }
        } else { // down
            if (board.count({pos[0], pos[1] - 2})) {
                pos[0] = pos[0]; pos[1] = pos[1] - 2; pos[2] = 1;
            } else if (board.count({pos[0] - 1, pos[1] - 1})) {
                pos[0] = pos[0] - 1; pos[1] = pos[1] - 1; pos[2] = 2;
            } else if (board.count({pos[0] - 1, pos[1]})) {
                pos[0] = pos[0] - 1; pos[1] = pos[1]; pos[2] = 2;
            } else if (board.count({pos[0] - 1, pos[1] + 1})) {
                pos[0] = pos[0] - 1; pos[1] = pos[1] + 1; pos[2] = 0;
            } else {
                pos[0] = pos[0]; pos[1] = pos[1]; pos[2] = 0;
            }
        }
    } else { // on a down triangle
        if (pos[2] == 0) { // left
            if (board.count({pos[0] - 1, pos[1]})) {
                pos[0] = pos[0] - 1; pos[1] = pos[1]; pos[2] = 2;
            } else if (board.count({pos[0] - 1, pos[1] + 1})) {
                pos[0] = pos[0] - 1; pos[1] = pos[1] + 1; pos[2] = 2;
            } else if (board.count({pos[0] - 1, pos[1] + 2})) {
                pos[0] = pos[0] - 1; pos[1] = pos[1] + 2; pos[2] = 0;
            } else if (board.count({pos[0], pos[1] + 1})) {
                pos[0] = pos[0]; pos[1] = pos[1] + 1; pos[2] = 0;
            } else {
                pos[0] = pos[0]; pos[1] = pos[1]; pos[2] = 1;
            }
        } else if (pos[2] == 1) { // up
            if (board.count({pos[0], pos[1] + 2})) {
                pos[0] = pos[0]; pos[1] = pos[1] + 2; pos[2] = 0;
            } else if (board.count({pos[0] + 1, pos[1] + 1})) {
                pos[0] = pos[0] + 1; pos[1] = pos[1] + 1; pos[2] = 0;
            } else if (board.count({pos[0] + 1, pos[1]})) {
                pos[0] = pos[0] + 1; pos[1] = pos[1]; pos[2] = 1;
            } else if (board.count({pos[0] + 1, pos[1] - 1})) {
                pos[0] = pos[0] + 1; pos[1] = pos[1] - 1; pos[2] = 1;
            } else {
                pos[0] = pos[0]; pos[1] = pos[1]; pos[2] = 2;
            }
        } else { // right
            if (board.count({pos[0] + 1, pos[1] - 2})) {
                pos[0] = pos[0] + 1; pos[1] = pos[1] - 2; pos[2] = 1;
            } else if (board.count({pos[0] + 1, pos[1] - 3})) {
                pos[0] = pos[0] + 1; pos[1] = pos[1] - 3; pos[2] = 1;
            } else if (board.count({pos[0], pos[1] - 2})) {
                pos[0] = pos[0]; pos[1] = pos[1] - 2; pos[2] = 2;
            } else if (board.count({pos[0], pos[1] - 1})) {
                pos[0] = pos[0]; pos[1] = pos[1] - 1; pos[2] = 2;
            } else {
                pos[0] = pos[0]; pos[1] = pos[1]; pos[2] = 0;
            }
        }
    }
}

bool point(int pos[2], int p){
    if (pos[1] % 2 == 0){
        if (board.count({pos[0],pos[1]+2}) && board[{pos[0],pos[1]+2}] == p &&
        board.count({pos[0]+1,pos[1]}) && board[{pos[0]+1,pos[1]}] == p){
            return true;
        }
    } else {
        if (board.count({pos[0]+1,pos[1]-2}) && board[{pos[0]+1,pos[1]-2}] == p &&
        board.count({pos[0]+1,pos[1]}) && board[{pos[0]+1,pos[1]}] == p){
            return true;
        }
    }
    return false;
}
pair<int,int> find_adj(int pos[3]){
    if (pos[1] % 2 == 0){
        if (pos[2] == 0) return {pos[0]-1, pos[1]+1};
        else if (pos[2] == 1) return {pos[0], pos[1]+1};
        else return {pos[0],pos[1]-1};
    } else {
        if (pos[2] == 0) return {pos[0]-1, pos[1]-1};
        else if (pos[2] == 1) return {pos[0], pos[1]+1};
        else return {pos[0]+1,pos[1]};
    }
}
tuple<int,int,int> relocate(){
    pair<int,int>maxx = {INT_MIN, INT_MIN};
    for (auto i:board){
        if (i.se > maxx.se) maxx = i;
        else if (i.se == maxx.se && i.fi < maxx.fi) maxx = i;
    }
    return {maxx.fi, maxx.se, 0};
}
void find_per(int[3] pos){
    int init[3];
    copy(pos.begin(),pos.end(),init.begin());
    int count = 0;
    do {
        next_pos(pos);
        count++;
    } while (pos != init);
    per = count;
}
void move(int times, int p){
    auto pos = poses[p], init = poses[p];
    find_per(pos);
    times %= per;
    times += per;
    for (int i = 0;i<times;i++){
        next_pos(pos);
        auto trg = find_adj(pos);
        if (!board.count({pos[0],pos[1]}) && point({trg[0], trg[1]}, p)){
            break;
        }
    }
    poses[p] = pos;
    auto trg = find_adj(init);
    board[{trg[0],trg[1]}] = p;
    if (int i = 0; i<times;i++){
        if (board.count(find_adj(poses[pos]))) {
            auto trg = relocate()
            poses[p][0] = trg[0]; poses[p][1] = trg[1]; poses[p][2] = trg[2];
        }
    }
    find_per(pos);
}
int main(){
    int p,m;cin>>p>>m;
    for (int i = 0;i<p;i++){
        cin>>trav[i];
        poses[i][0] = 0; poses[i][1] = 0; poses[i][2] = 0;
    }
    board[{0,0}] = 0;
    for (int i = 0;i<m;i++){
        for (int j = 0;j<p;j++){
            move(trav[j], j);
        }
    }
    cout<<per<<endl;
}   