#include <bits/stdc++.h>
using namespace std;
#define long long ll;
signed main(){
    int t;cin>>t;
    for (int cas = 0;cas<t;cas++){
        int n;cin>>n;
        int a[n];
        int cnt = 0, prev = 0;
        for (int i = 0;i<n;i++){
            cin>>a[i];
            if (a[i] != 0 && prev == 0) cnt++;
            prev = a[i];
        }
        if (cnt == 0){
            cout<<0<<endl;
        } else if (cnt == 1){
            cout<<1<<endl;
        } else{
            cout<<2<<endl;
        }
    }
}