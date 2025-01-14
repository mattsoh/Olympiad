#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        int n, k;
        cin >> n >> k;  // Read n and k for each test case
        
        vector<int> permutation(n, 0);  // Initialize the permutation array with zeros
        
        // Fill positions that affect the minimum of subarrays of length k
        int idx = 1;
        for (int i = k - 1; i < n; i += k) {
            permutation[i] = idx++;  // Place the smallest numbers at every k-th position
        }
        
        // Fill the remaining positions with the rest of the numbers
        vector<int> remaining;
        for (int i = 0; i < n; i++) {
            if (permutation[i] == 0) {
                remaining.push_back(idx++);
            }
        }
        
        int r_idx = 0;
        for (int i = 0; i < n; i++) {
            if (permutation[i] == 0) {
                permutation[i] = remaining[r_idx++];
            }
        }
        
        // Print the permutation
        for (int i = 0; i < n; i++) {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();  // Solve the problem
    return 0;
}
