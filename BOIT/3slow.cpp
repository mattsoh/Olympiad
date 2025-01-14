#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
vector<vector<ll>>poss[80];
ll score = 0;
int main(){
    string word;cin>>word;
    vector<ll>w;
    for (auto i:word){
        score += (ll) i - 64;
        w.push_back((ll) i - 64);
    }
    w.push_back(0);
    reverse(w.begin(),w.end());
    cout<<score<<endl;
    poss[0].push_back(vector<ll>({0}));
    for (ll i = 1;i<=score;i++){
        for (ll prev = i-1; prev >= max(0ll,i-26);prev--){
            // if (prev == 0)poss[i].push_back(vector<ll>({i}));continue;
            for (auto j:poss[prev]){
                // cout<<i<<' '<<prev<<' '<<j<<(char)(i-prev+64)<<endl;
                // cout<<j.back()<<endl;
                // if (!j.empty())cout<<i-prev<<' '<<j[0]<<endl;
                if (!j.empty() && i-prev != j.back()){
                    j.push_back(i-prev);
                    poss[i].push_back(j);
                }
            }
        }
    }
    // for (auto i:poss[score]){
    //     for (auto j:i){
    //         // cout<<j<<' ';
    //         cout<<(char) (j+64);
    //     }
    //     cout<<endl;
    // }
    // for (auto i:w)cout<<i<<' ';
    // cout<<endl;
    // cout<< find(poss[score].begin(),poss[score].end(),w) - poss[score].begin() + 1<<endl;
    for (auto i:poss[score]){
        
    }
}