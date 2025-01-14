#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second

ll trav[10];
ll per = 3;
map<pair<ll, ll>, ll> board;
tuple<ll, ll, ll> poses[10];
ll polls[10];

array<ll,3> next_pos(array<ll,3>& pos, array<ll,3>& init){
    cout<<pos[0]<<pos[1]<<pos[2]<<"initposbeingch"<<endl;
    cout<<init[0]<<init[1]<<init[2]<<""<<endl;
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
    cout<<pos[0]<<pos[1]<<pos[2]<<"finalpos"<<endl;
    return pos;
}
bool poll(pair<ll,ll> tt, ll p){
    ll pos[2];
    pos[0] = tt.fi;pos[1] = tt.se;
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
pair<ll, ll> find_adj(const array<ll, 3>& pos) {
    if (pos[1] % 2 == 0) {
        if (pos[2] == 0) return {pos[0] - 1, pos[1] + 1};
        else if (pos[2] == 1) return {pos[0], pos[1] + 1};
        else return {pos[0], pos[1] - 1};
    } else {
        if (pos[2] == 0) return {pos[0], pos[1] - 1};
        else if (pos[2] == 1) return {pos[0], pos[1] + 1};
        else return {pos[0] + 1, pos[1]};
    }
}
// (i.first.second > maxx.second && (i.first.second%2 == 1 && i.first.first < maxx.first)) || (i.first.second%2 == 0)) || (i.first.second == maxx.second && i.first.first < maxx.first) || (i.first.second%2==0 && i.first.second+1 == maxx.second && i.first.first <= maxx.first)
tuple<ll, ll, ll> relocate() {
    pair<ll, ll> maxx = {LLONG_MAX, LLONG_MIN};
    for (auto i : board) {
        bool a = (i.fi.se > maxx.se && ((i.fi.se%2 == 1 && i.fi.fi < maxx.fi) || (i.fi.se%2 == 0)));
        bool b = (i.fi.se == maxx.se && i.fi.fi < maxx.fi) ;
        bool c = (i.fi.se%2==0 && i.fi.se+1 == maxx.se && i.fi.fi <= maxx.fi);
        if (a||b||c) {
            maxx = i.fi;
            
        }
    }
    return {maxx.fi, maxx.se, 0};
}

void find_per(array<ll, 3>& pos) {
    array<ll, 3> init = pos;
    ll count = 0;
    do {
        pos = next_pos(pos,init);
        count++;

    } while (pos != init);
    per = count;
}

void move(ll times, ll p) {
    array<ll, 3> pos = {get<0>(poses[p]), get<1>(poses[p]), get<2>(poses[p])};
    array<ll, 3> init = pos;

    find_per(pos);
    if (times > per) {
        times %= per;
        times += per;
    }
    for (ll i = 0; i < times; i++) {
        pos = next_pos(pos,init);
        auto trg = find_adj(pos);
        if (!board.count(trg) && poll(trg, p)) {
            break;
        }
    }

    poses[p] = {pos[0], pos[1], pos[2]};
    auto trg = find_adj(init);
    board[trg] = p;

    for (ll i = 0; i < times; i++) {
        if (board.count(find_adj({get<0>(poses[i]), get<1>(poses[i]), get<2>(poses[i])}))) {
            auto trg1 = relocate();
            poses[i] = trg1;
        }
    }
    find_per(pos);
}

int main() {
    ll p, m;
    cin >> p >> m;

    for (ll i = 0; i < p; i++) {
        cin >> trav[i];
        poses[i] = {0, 0, 0};
    }

    board[{0, 0}] = -1; 
    ll player = 0;
    for (ll i = 0; i < m; i++) {
        move(trav[player], player);
        player = (player + 1)%p;
    }
    
    for (auto i:board){
        if (poll(i.fi,i.se)) polls[i.se]++;
    }
    for (ll i = 0;i<p;i++){
        cout<<polls[i]<<endl;
    }
    cout << per << endl;
    return 0;
}
