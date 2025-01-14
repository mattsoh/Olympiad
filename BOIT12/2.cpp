#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
struct pile {
    pair<int,int> top;
    int count;
};
int shuf[6];
vector<pile> piles;
bool piled[52];
char spec[4] = {'T','J','Q','K'},suits[4] = {'C','H','S', 'D'};
string card_rep(pair<int,int> p) {
    string s = "";
    if (p.fi == 1) {
        s += 'A';
    } else if (p.fi < 10) {
        s += '0' + p.fi;
    } else {
        s += spec[p.fi - 10];
    }
    s += suits[p.se];
    return s;
}
bool valid(pile a, pile b) {
    return a.top.fi == b.top.fi || a.top.se == b.top.se;
}

int main(){
    for (int i = 0;i<6;i++){
        cin>>shuf[i];
    }
    int taken = 0, curr = -1, card = 0, shufpos = 0;
    while (taken < 52) {
        do {
            curr  = (curr+1)%52;
        } while (piled[curr]);
        card++;
        if (card == shuf[shufpos]) {
            piles.push_back({{curr%13 + 1,curr/13},1});
            piled[curr] = true;
            taken++;
            card = 0;
            shufpos = (shufpos + 1) % 6;
        }
    }
    cout<<card_rep(piles[0].top)<<' '<<card_rep(piles.back().top)<<endl;
    // Strat 1
    vector<pile> pile1 = piles;
    while (pile1.size() > 1) {
        bool found = false;
        for (int i = pile1.size()-1; i >= 0; i--) {
            for (int j = i-1; j >= i-3; j -= 2) {
                if (j < 0) break;
                if (valid(pile1[i],pile1[j])) {
                    pile1[j].count += pile1[i].count;
                    pile1[j].top = pile1[i].top;
                    pile1.erase(pile1.begin() + i);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        
        if (!found) break;
    }
    cout<<pile1.size()<<' '<<card_rep(pile1[0].top)<<endl;

    // Strat 2
    vector<pile> pile2 = piles;
    while (pile2.size() > 1) {
        bool found = false;
        int maxc = 0, posj = -1, posi = -1;
        for (int i = pile2.size()-1; i >= 0; i--) {
            for (int j = i-1; j >= i-3; j -= 2) {
                if (j < 0) break;
                if (valid(pile2[i],pile2[j])) {
                    if (pile2[i].count + pile2[j].count > maxc) {
                        maxc = pile2[i].count + pile2[j].count;
                        posj = j;
                        posi = i;
                        found = true;
                    }
                }
            }
        }
        if (!found) break;
        pile2[posj].count += pile2[posi].count;
        pile2[posj].top = pile2[posi].top;
        pile2.erase(pile2.begin() + posi);
    }
    cout<<pile2.size()<<' '<<card_rep(pile2[0].top)<<endl;

    // Strat 3
    vector<pile> pile3 = piles;
    while (pile3.size() > 1) {
        bool found = false;
        int largev = -1, posj = -1, posi = -1;
        for (int i = pile3.size()-1; i >= 0; i--) {
            for (int j = i-1; j >= i-3; j -= 2) {
                if (j < 0) break;
                if (valid(pile3[i],pile3[j])) {
                    vector<pile> temp = pile3;
                    temp[j].top = temp[i].top;
                    temp.erase(temp.begin() + i);
                    int count = 0;
                    for (int newi = temp.size()-1;newi >= 0; newi--) {
                        for (int newj = newi-1; newj >= newi-3; newj -= 2) {
                            if (newj < 0) break;
                            if (valid(temp[newi],temp[newj])) {
                                count++;
                            }
                        }
                    }
                    if (count > largev) {
                        largev = count;
                        posj = j;
                        posi = i;
                        found = true;
                    }
                    
                }
            }
        }
        if (!found) break;
        pile3[posj].count += pile3[posi].count;
        pile3[posj].top = pile3[posi].top;
        pile3.erase(pile3.begin() + posi);
    }
    cout<<pile3.size()<<' '<<card_rep(pile3[0].top)<<endl;
}