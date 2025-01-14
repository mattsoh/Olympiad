#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll word[10];
ll sdial[26];
int main(){
    ll n;cin>>n;
    string w;cin>>w;
    ll wcount = 0;
    for (auto i:w){
        word[wcount++] = (ll) i - 'A';
    }
    vector<ll> tp;
    // for (ll i = 0;i<26;i++){
    //     tp.push_back(i);
    // }
    ll t = -1;
    for (ll i = 0;i<26;i++){
        ll j = 0;
        while (j < (n%((26-i)))){
            // for (ll k = 0;k<26;k++)cout<<tp[k]<<' ';
            if (find(tp.begin(),tp.end(),(++t)%(26)) == tp.end()){
                j++;
            }
        }
        sdial[i] = (t%26);
        tp.push_back((t%26));
    }
    for (ll i = 0;i<6;i++)cout<<(char)(tp[i]+'A');
    cout<<endl;
    for (ll i = 0;i<wcount;i++){
        cout<<(char)(tp[(word[i]+i)%26] +'A');
    }
    cout<<endl;
}