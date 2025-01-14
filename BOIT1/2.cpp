#include <bits/stdc++.h>

using namespace std;

const int maxn = 10;
set<string> shapes;
vector<vector<int>> canvas(maxn, vector<int>(maxn, 0));

map<char, vector<vector<int>>> pents = {
    {'F', {{0, 1, 1}, {1, 1, 0}, {0, 1, 0}}},
    {'G', {{1, 1, 0}, {0, 1, 1}, {0, 1, 0}}},
    {'I', {{1}, {1}, {1}, {1}, {1}}},
    {'L', {{1, 0}, {1, 0}, {1, 0}, {1, 1}}},
    {'J', {{0, 1}, {0, 1}, {0, 1}, {1, 1}}},
    {'N', {{0, 1}, {1, 1}, {1, 0}, {1, 0}}},
    {'M', {{1, 0}, {1, 1}, {0, 1}, {0, 1}}},
    {'P', {{1, 1}, {1, 1}, {1, 0}}},
    {'Q', {{1, 1}, {1, 1}, {0, 1}}},
    {'T', {{1, 1, 1}, {0, 1, 0}, {0, 1, 0}}},
    {'U', {{1, 0, 1}, {1, 1, 1}}},
    {'V', {{1, 0, 0}, {1, 0, 0}, {1, 1, 1}}},
    {'W', {{1, 0, 0}, {1, 1, 0}, {0, 1, 1}}},
    {'X', {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}}},
    {'Z', {{1, 1, 0}, {0, 1, 0}, {0, 1, 1}}},
    {'S', {{0, 1, 1}, {0, 1, 0}, {1, 1, 0}}},
    {'Y', {{0, 1}, {1, 1}, {0, 1}, {0, 1}}},
    {'A', {{1, 0}, {1, 1}, {1, 0}, {1, 0}}}
};

bool draw_shape(vector<vector<int>> shape, int ox, int oy, int cell_fill) {
    for (int y = 0; y < shape.size(); y++) {
        for (int x = 0; x < shape[0].size(); x++) {
            if (shape[y][x] == 0) continue;
            if (canvas[oy + y][ox + x] != 0) return false;
            canvas[oy + y][ox + x] = cell_fill;
        }
    }
    return true;
}

bool touching() {
    for (int y = 0; y < maxn; y++) {
        for (int x = 0; x < maxn; x++) {
            if (canvas[y][x] == 0) continue;
            if (x > 0 && canvas[y][x] != canvas[y][x - 1] && canvas[y][x - 1] != 0) return true;
            if (x < maxn - 1 && canvas[y][x] != canvas[y][x + 1] && canvas[y][x + 1] != 0) return true;
            if (y > 0 && canvas[y][x] != canvas[y - 1][x] && canvas[y - 1][x] != 0) return true;
            if (y < maxn - 1 && canvas[y][x] != canvas[y + 1][x] && canvas[y + 1][x] != 0) return true;
        }
    }
    return false;
}

vector<vector<int>> trim() {
    int left = maxn, right = -1, up = maxn, down = -1;
    for (int y = 0; y < maxn; y++) {
        for (int x = 0; x < maxn; x++) {
            if (canvas[y][x] != 0) {
                left = min(left, x);
                right = max(right, x);
                up = min(up, y);
                down = max(down, y);
            }
        }
    }
    vector<vector<int>> res;
    for (int y = up; y <= down; y++) {
        vector<int> row;
        for (int x = left; x <= right; x++) {
            row.push_back(canvas[y][x]);
        }
        res.push_back(row);
    }
    for (int y = 0; y < res.size(); y++) {
        for (int x = 0; x < res[0].size(); x++) {
            if (res[y][x] != 0) res[y][x] = 1;
        }
    }
    return res;
}

string encode(vector<vector<int>> shape) {
    stringstream ss;
    for (auto row : shape) {
        for (int cell : row) {
            ss << cell;
        }
        ss << endl;
    }
    return ss.str();
}

void clear() {
    for (int y = 0; y < maxn; y++) {
        for (int x = 0; x < maxn; x++) {
            canvas[y][x] = 0;
        }
    }
}
// void partb(){
//     // add code from part a here also, input 'XW'
//     set<string> resb;
//     for (auto i:pents){
//         if (i.first == 'X' || i.first == 'W') continue;
//         for (auto j:pents){
//             if (i.first == j.first) continue;
//             for (int o1x = 0; o1x <= maxn - i.second[0].size(); o1x++) {
//                 for (int o1y = 0; o1y <= maxn - i.second.size(); o1y++) {
//                     for (int o2x = 0; o2x <= maxn - j.second[0].size(); o2x++) {
//                         for (int o2y = 0; o2y <= maxn - j.second.size(); o2y++) {
//                             clear();
//                             draw_shape(i.second, o1x, o1y, 1);
//                             bool ret = draw_shape(j.second, o2x, o2y, 2);
//                             if (!ret || !touching()) continue;
//                             vector<vector<int>> complete_shape = trim();
//                             if (shapes.find(encode(complete_shape)) != shapes.end()) {
//                                 resb.insert(encode(complete_shape));
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     // for (auto complete_shape:resb){
//     //     cout<<complete_shape<<endl;
//     // }
//     cout<<resb.size()<<endl;
// }
int main() {
    char s1, s2;
    cin >> s1 >> s2;
    for (int o1x = 0; o1x <= maxn - pents[s1][0].size(); o1x++) {
        for (int o1y = 0; o1y <= maxn - pents[s1].size(); o1y++) {
            for (int o2x = 0; o2x <= maxn - pents[s2][0].size(); o2x++) {
                for (int o2y = 0; o2y <= maxn - pents[s2].size(); o2y++) {
                    clear();
                    draw_shape(pents[s1], o1x, o1y, 1);
                    bool ret = draw_shape(pents[s2], o2x, o2y, 2);
                    if (!ret || !touching()) continue;
                    vector<vector<int>> complete_shape = trim();
                    shapes.insert(encode(complete_shape));
                }
            }
        }
    }
    
}