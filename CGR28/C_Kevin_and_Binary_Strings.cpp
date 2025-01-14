#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll xor_value(string a, string b) {
    ll a_val = 0, b_val = 0;
    for (char c : a) {
        a_val = (a_val << 1) | (c - '0');
    }
    
    for (char c : b) {
        b_val = (b_val << 1) | (c - '0');
    }
    return a_val ^ b_val;
}

void solve() {
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;  // Read the binary string for the current test case
        
        ll n = s.length();
        

        ll l1 = 1, r1 = n;
        
        // We are now looking for the second substring.
        ll max_xor = -1;
        ll l2 = -1, r2 = -1;
        
        // Try every possible second substring
        for (ll i = 0; i < n; ++i) {
            for (ll j = i; j < n; ++j) {
                // The second substring is from index i to j
                string sub1 = s.substr(0, n);  // the first substring is the entire string
                string sub2 = s.substr(i, j - i + 1);  // the second substring
                
                ll current_xor = xor_value(sub1, sub2);
                
                // If the current XOR is greater than the previous maximum, update it
                if (current_xor > max_xor) {
                    max_xor = current_xor;
                    l2 = i + 1;  // 1-based index
                    r2 = j + 1;  // 1-based index
                }
            }
        }
        
        // Output the result
        cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    }
}

signed main() {
    solve();
    return 0;
}
