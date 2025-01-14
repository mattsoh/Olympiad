#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << (n%33 ? "YES" : "NO") << endl;
    }
    return 0;
}
