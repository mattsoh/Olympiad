#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    double interest,repay; cin>>interest>>repay;
    interest /=100;
    repay /= 100;
    ll debt = 100 * 100;
    ll topay = 0;
    int c = 0;
    while (debt > 0){
        c++;
        cout<<debt<<endl;
        debt += debt * interest;
        topay += ceil((ll) min((double)debt,max(5000.0,repay * debt)));
        debt -= ceil((ll) min((double)debt,max(5000.0,repay * debt)));
    }
    cout<<ceil(topay*100)/10000<<endl;
}