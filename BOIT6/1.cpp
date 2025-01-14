#include <bits/stdc++.h>
using namespace std;
map<string,string> rgb = {{"RG","B"},{"RB","G"},{"GB","R"}, {"GR","B"},{"BR","G"},{"BG","R"}};
string ad = "RGB";
set<string> add(string s, int len){
    // cout<<s<<endl;
    if (s.size() ==len ) return {s};
    set<string>res;
    for (auto i:ad){
        auto ans = add(s+i, len);
        res.insert(ans.begin(),ans.end());
    }
    return res;
}
int main(){
    string inp;cin>>inp;
    while(inp.size() > 1){
        string n;
        for (int i = 0;i<inp.size()-1;i++){
            string add;
            add.push_back(inp[i]);
            add.push_back(inp[i+1]);
            if (inp[i] == inp[i+1])n.push_back(inp[i]);
            else n += rgb[add];
        }
        inp = n;
    }
    cout<<inp<<endl;
}
// void b(){
//     // string inp;cin>>inp;
//     for (auto inp:add("", 9)){
//         string n;
//         for (int i = 0;i<inp.size()-1;i++){
//             string add;
//             add.push_back(inp[i]);
//             add.push_back(inp[i+1]);
//             if (inp[i] == inp[i+1])n.push_back(inp[i]);
//             else n += rgb[add];
//         }
//         if (n == "RRGBRGBB")cout<<inp<<endl;
//     }
//     // cout<<inp<<endl;
// }
// string ck(string inp){
//     while(inp.size() > 1){
//         string n;
//         for (int i = 0;i<inp.size()-1;i++){
//             string add;
//             add.push_back(inp[i]);
//             add.push_back(inp[i+1]);
//             if (inp[i] == inp[i+1])n.push_back(inp[i]);
//             else n += rgb[add];
//         }
//         inp = n;
//     }
//     return inp;
// }
// void d(){
//     for (int i = 1;i<200;i++){
//         // cout<<i<<endl;
//         bool fs = true;
//         for (auto poss:add("",i)){
//             // cout<<poss<<endl;
//             string other;
//             other.push_back(poss[0]);
//             other.push_back(poss[poss.size()-1]);
//             // cout<<poss<<' '<<other<<' '<<ck(poss)<<' '<<ck(other)<<endl;
//             if (ck(poss) != ck(other)) {fs = false; break;}
//         }
//         if (fs) cout<<i<<endl;
//     }
// }