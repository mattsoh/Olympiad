#include <bits/stdc++.h>
using namespace std;
int cost[10][26];
int dist[1010][1010];
array<int, 26> getCount(int x){
    vector<int> ans;
    while (x >= 1) {
        ans.push_back(x%10);
        x /= 10;
    }
    array<int,26> cnt;
    for (int i = 0;i<26;i++){
        cnt[i] = 0;
    }
    for (auto i:ans){
        for (int j = 0;j<26;j++){
            cnt[j] += cost[i][j];
        }
    }
    return cnt;
}
bool valid(int a, int b){
    array<int,26> cnta = getCount(a);
    array<int,26> cntb = getCount(b);
    int ccc = 0;
    for (int i = 0;i<26;i++){
        ccc += abs(cnta[i] - cntb[i]);
    }
    return ccc <= 5;
}
void setup(){
    cost[0]['Z' - 'A'] = 1;
    cost[0]['E' - 'A'] = 1;
    cost[0]['R' - 'A'] = 1;
    cost[0]['O' - 'A'] = 1;
    cost[1]['O' - 'A'] = 1;
    cost[1]['N' - 'A'] = 1;
    cost[1]['E' - 'A'] = 1;
    cost[2]['T' - 'A'] = 1;
    cost[2]['W' - 'A'] = 1;
    cost[2]['O' - 'A'] = 1;
    cost[3]['T' - 'A'] = 1;
    cost[3]['H' - 'A'] = 1;
    cost[3]['R' - 'A'] = 1;
    cost[3]['E' - 'A'] = 2;
    cost[4]['F' - 'A'] = 1;
    cost[4]['O' - 'A'] = 1;
    cost[4]['U' - 'A'] = 1;
    cost[4]['R' - 'A'] = 1;
    cost[5]['F' - 'A'] = 1;
    cost[5]['I' - 'A'] = 1;
    cost[5]['V' - 'A'] = 1;
    cost[5]['E' - 'A'] = 1;
    cost[6]['S' - 'A'] = 1;
    cost[6]['I' - 'A'] = 1;
    cost[6]['X' - 'A'] = 1;
    cost[7]['S' - 'A'] = 1;
    cost[7]['E' - 'A'] = 2;
    cost[7]['V' - 'A'] = 1;
    cost[7]['N' - 'A'] = 1;
    cost[8]['E' - 'A'] = 1;
    cost[8]['I' - 'A'] = 1;
    cost[8]['G' - 'A'] = 1;
    cost[8]['H' - 'A'] = 1;
    cost[8]['T' - 'A'] = 1;
    cost[9]['N' - 'A'] = 2;
    cost[9]['I' - 'A'] = 1;
    cost[9]['E' - 'A'] = 1;
}
int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    setup();
    for (int i = 0;i<1000;i++){
        for (int j = 0;j<1000;j++){
            dist[i][j] = -1;
        }
    }
    for (int ff = 0;ff<3;ff++){
        int s,f;cin>>s>>f;
        dist[s][s] = 0;
        if (dist[s][f] != -1){
            cout<<dist[s][f]<<endl;
            continue;
        }
        queue<int> q;
        q.push(s);
        while (!q.empty()){
            int curr = q.front();q.pop();
            if (curr == f) break;
            for (int i = 0;i<1000;i++){
                if (curr == i) continue;
                if (valid(curr, i)) {
                    if (dist[s][i] == -1 || dist[s][i] > dist[s][curr] + 1){
                        dist[s][i] = dist[s][curr] + 1;
                        q.push(i);
                    }
                } else if (dist[curr][i] != -1) {
                        if (dist[s][i] == -1 || dist[s][i] > dist[s][curr] + dist[curr][i]){
                            dist[s][i] = dist[s][curr] + dist[curr][i];
                            q.push(i);
                        }
                    }
            }
        }
        cout<<dist[s][f]<<endl;
    }
}