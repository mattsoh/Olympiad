#include <bits/stdc++.h>
using namespace std;
map<string,bool> isPat;
void pat (string x){
    if (x.length() == 1){
        isPat.insert({x,true});
        return;
    }
    for (int i = 1;i<x.length();i++){
        string a = x.substr(0,i), b = x.substr(i);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int minn = 100;
        for (auto j:a){
            minn = min(minn,(int)j);
        }
        bool fail = false;
        for (auto j:b){
            if ((int) j >= minn){
                fail = true;
                break;
            }
        }
        if (fail) continue;
        if (!isPat.count(a)) pat(a);
        if (!isPat.count(b)) pat(b);
        if (isPat[a] && isPat[b]){
            isPat.insert({x,true});
            return;
        }
    }
    isPat.insert({x,false});
}
int main(){
    string a,b;cin>>a>>b;
    pat(a);
    pat(b);
    pat(a+b);
    if (isPat[a])cout<<"YES"<<endl; else cout<<"NO"<<endl;
    if (isPat[b])cout<<"YES"<<endl; else cout<<"NO"<<endl;
    if (isPat[a+b])cout<<"YES"<<endl; else cout<<"NO"<<endl;
    vector<int> pats = {0,1};
    for (int i = 2;i<25;i++){
        int a = 1, b= i - 1;
        int counter = 0;
        while (b > 0 && a < i){
            counter += pats[a] * pats[b];
            a += 1;
            b -= 1;
        pats.push_back(counter);
    }

    }
    cout<<pats[24]<<endl;
}