#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    unordered_set<int> cant[n]; // num cant have this position
    unordered_set<int> can[n]; // num can have this position
    for (int i = 0;i<n;i++){
        if (s[i] == 's'){
            for (int k = 0;k<n-i;k++){
                for (int j = 0;j<i;j++){
                    cant[k].insert(j);
                }
            }
        } else if (s[i] == 'p') {
            for (int k = 0;k<=i;k++){
                for (int j = i+1;j<n;j++){
                    cant[k].insert(j);
                }
            }
        }
    }
    for (int i = 0;i<n;i++){
        if (s[i] == 's'){
            for (int k = 0;k<n-i;k++){
                for (int j = i;j<n;j++){
                    if (cant[k].find(j) != cant[k].end()){
                        can[j].insert(k);
                    }
                }
            }
        } else if (s[i] == 'p') {
            for (int k = 0;k<=i;k++){
                for (int j = 0;j<=i;j++){
                    if (cant[k].find(j) != cant[k].end()){
                        can[j].insert(k);
                    }
                }
            }
        } else if (s[i] == '.'){
            for (int j = 0;j<n;j++){
                if (cant[j].find(i) != cant[j].end()){
                    can[i].insert(j);
                }
            }
        }
    }
    for (int i = 0;i<n;i++){
        cout<<i<<"cant: ";
        
        for (auto x:cant[i]){
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<i<<": cann";
        for (auto x:cant[i]){
            cout<<x<<" ";
        }
        cout<<endl;
        if (cant[i].size() == n){
            cout<<"NO"<<endl;
            return;
        } else{
            
        }
        if (can[i].size() == 0){
            cout<<"NO"<<endl;
            return;
        }else{
            
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    int t;cin>>t;
    while (t--)solve();
}