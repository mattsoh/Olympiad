#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e8;
int pals[maxn];
set<vector<ll>> poss;
bool palindrome(int x){
    if (pals[x] != -1) return pals[x];
    stringstream num;num<<x;
    string num_string = num.str();
    string rev = num_string;
    reverse(rev.begin(), rev.end());
    if (num_string == rev){
        pals[x] = 1;
        // cout<<x<<endl;
        return true;
    } else{
        pals[x] = 0;
        return false;
    }
}
void dfs(int depth, int num, int prev, vector<ll> prev_nums){
    cout<<"start"<<endl;
    cout<<depth<<' '<<num<<' '<<prev<<prev_nums[0]<<prev_nums[1]<<prev_nums[2]<<endl;
    cout<<"hello"<<endl;
    if (palindrome(num)){
        prev_nums.push_back(num);
        poss.insert(prev_nums);
    }
    if (depth == 4) return;
    for (int i = prev;i< num;i++){
        vector<ll> tmp;
        tmp.push_back(i);
        dfs(depth+1, num-i, i,tmp );
    }
}
int main(){
    cout<<"Matthew Soh, The Perse School"<<endl;
    int num;cin>>num;
    for (int i = 0;i<=num+2;i++){
        pals[i] = -1;
    }
    if (palindrome(num)){
        cout<<num<<endl;
        return 0;
    }
    cout<<"dfsing"<<endl;
    dfs(0,num, 0, {});
    cout<<"finished"<<endl;
    for (auto i:poss){
        for (auto j:i){
            cout<<j<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}