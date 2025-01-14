#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int strat[2][6];
const char P[2] = {'F', 'S'}, NT = '*', EM = '.';
const pair<int,int> DIRS[8] = {{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};
pair<int,int> pieceposes[2][6];
pair<int,int> neutronpos = {2,2};
char grid[5][5];
int win(pair<int,int> pos){
    if (pos.se == 0) return 1;
    else if (pos.se == 4) return 0;
    return -1;
}
pair<int,int> poss_move(pair<int,int> pos, int dir){
    while (true){
        pair<int,int> next_pos = {pos.fi + DIRS[dir].fi, pos.se + DIRS[dir].se};
        if (grid[next_pos.se][next_pos.fi] != EM || 
        !(0 <= next_pos.fi && next_pos.fi < 5 && 0 <= next_pos.se && next_pos.se < 5)){
            break;
        }
        pos = next_pos;
    }
    return pos;
}
void move(int player, int piece, pair<int,int> orig, pair<int,int> fin){
    if (piece == 0) {
        neutronpos = fin;
        grid[fin.se][fin.fi] = NT;
    } else {
        pieceposes[player][piece] = fin;
        grid[fin.se][fin.fi] = P[player];
    }
    grid[orig.se][orig.fi] = EM;
}
bool move_turn(int player, int turn){
    pair<int,int> next_moves[8];
    for (int dir = 0;dir<8;dir++){
        next_moves[dir] = poss_move(neutronpos, dir);
        if (next_moves[dir] == neutronpos) continue;
        int neutron_winning = win(next_moves[dir]);
        if (neutron_winning == player) {
            // cout<<player<<" is going to win"<<endl;
            move(player, 0, neutronpos, next_moves[dir]);
            return true;
        }
    }
    int piece = strat[player][turn];
    // cout<<"working with piece "<<piece<<endl;
    pair<int,int> piecepos = pieceposes[player][piece];
    // cout<<"player is "<<player<<endl;
    // cout<<"position is "<<piecepos.fi<<piecepos.se<<endl;
    for (int dir = 0;dir<8;dir++){
        if (next_moves[dir] == neutronpos) continue;
        if (win(next_moves[dir]) == -1 && next_moves[dir] != neutronpos) {
            pair<int,int> orig_neutronpos = neutronpos;
            move(player, 0, neutronpos, next_moves[dir]);
            for (int piecedir = 0; piecedir<8;piecedir++){
                pair<int,int> poss_piecepos = poss_move(piecepos, piecedir);
                if (poss_piecepos != piecepos) {
                    move(player, piece, piecepos, poss_piecepos);
                    return false;
                }
            }
            move(player, 0, neutronpos, orig_neutronpos);
        } 
    }
    for (int dir = 0;dir<8;dir++){
        if (next_moves[dir] != neutronpos){
            move(player, 0, neutronpos, next_moves[dir]);
            return true;
        }
    } 
    return false;
}
void print(){
    cout<<endl;
    for (int i = 0;i<5;i++){
        for (int j = 0;j<5;j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}

int main(){
    // cout<<"Matthew Soh, 14 years old, The Perse School Cambridge"<<endl;
    for (int i = 0;i<=5;i++){
        for (int j = 1;j<=5;j++){
            grid[i][j] = EM;
        }
    }
    for (int i = 0;i<2;i++){
        for (int j = 1;j<=5;j++){
            cin>>strat[i][j];
        }
    }
    for (int i = 0;i<5;i++){
        pieceposes[0][i+1] = {i,4};
        grid[4][i] = P[0];
    }
    for (int i = 0;i<5;i++){
        pieceposes[1][i+1] = {i,0};
        grid[0][i] = P[1];
    }
    grid[2][2] = NT;
    // print();
    int player = 0, turns = 0;
    while (win(neutronpos) == -1){
        // cout<<"strat "<<((turns-player)/2)%5 + 1<<endl;
        if (move_turn(player, ((turns-player)/2)%5 + 1)) break;
        player = 1-player;
        if (turns < 2) print();
        turns++;
        // print();
    }
    print();
    // cout<<neutronpos.fi<<' '<<neutronpos.se<<endl;
}