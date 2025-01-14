#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

void solve() {
    int t;
    cin >> t;  // Read the number of test cases
    
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;  // Read n, x, y for each test case
        
        // Initialize an array to store values assigned to each dragon
        vector<int> a(n, -1);  // -1 means unassigned
        
        // Assign initial values to dragons x and y
        a[x - 1] = 0;
        a[y - 1] = 1;
        
        // Use a queue for BFS
        queue<int> q;
        q.push(x - 1);
        q.push(y - 1);
        
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            
            // Calculate the MEX of the neighbors of dragon i
            vector<int> neighbors = {(i - 1 + n) % n, (i + 1) % n};  // The circular neighbors
            unordered_set<int> neighbor_vals;
            
            // Collect the values of neighbors
            for (int neigh : neighbors) {
                if (a[neigh] != -1) {
                    neighbor_vals.insert(a[neigh]);
                }
            }
            
            // Find the MEX value
            int mex = 0;
            while (neighbor_vals.count(mex)) {
                mex++;
            }
            
            // Assign MEX value to unassigned neighbors
            for (int neigh : neighbors) {
                if (a[neigh] == -1) {
                    a[neigh] = mex;
                    q.push(neigh);
                }
            }
        }
        
        // Output the result for this test case
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
