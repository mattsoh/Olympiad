#include <bits/stdc++.h>
using namespace std;
map<int,char, greater<int>> cc = {{1,'I'}, {5,'V'}, {10,'X'}, {50,'L'}, {100,'C'},{500,'D'},{1000,'M'}};
map<int,string> exep = {{4, "IV"}, {9,"IX"}, {40, "XL"}, {90,"XC"},{400,"CD"},{900,"CM"}};
// vector<string> romans;
// set<string>d;
#define fi first
#define se second
string conv(int x){
    if (exep.count(x)){
        return exep[x];
    }
    string final = "";
    for (auto i:cc){
        while (i.fi <= x){
            if (exep.count(x)){
                final += exep[x];
                return final;
            }
            final += i.se;
            x -= i.fi;
        }
    }
    return final;
}
string desc(string x){
    char prev = 'a';
    int count = 0;
    string fin = "";
    for (auto i:x){
        if (i == prev) count++;
        else {
            fin += conv(count);
            if (count > 0) fin += prev;
            prev = i;
            count = 1;
        }
    }
    fin += conv(count);
    if (count > 0) fin += prev;
    return fin;

}
int main(){
    string init;cin>>init;
    int n;cin>>n;
    for (int i = 0;i<n;i++){
        init = desc(init);
    }
    int vc = 0;
    int ic = 0;
    for (auto i:init){
        if (i == 'V') vc++;
        else if (i == 'I') ic++;
    }
    cout<<ic<<' '<<vc<<endl;
}
// void b(){
//     for (int i = 1;i<=3999;i++){
//         romans.push_back(conv(i));
//     }
//     for (int i = 1;i<=3999;i++){
//         if (find(romans.begin(),romans.end(),desc(conv(i))) != romans.end()){
//             cout<<desc(conv(i))<<endl;
//         }
//     }
// }
// void c(){
//     int c = 0;
//     for (int i = 1;i<=3999;i++){
//         d.insert(desc(conv(i)));
//     }
//     cout<<d.size()<<endl;
// }
