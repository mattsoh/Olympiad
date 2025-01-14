#include <bits/stdc++.h>
using namespace std;
vector<int> comp(int n){
    vector<int> ans;
    while (n){
        ans.push_back(n%10);
        n/=10;
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n;cin>>n;
    vector<int> orig = comp(n);
    bool chg = false;
    for (int i = 2;i<10;i++){
        if (comp(n*i) == orig) {
            cout<<i<<' ';
            chg = true;
        }
    }
    if (!chg)cout<<"NO";
    cout<<endl;
}