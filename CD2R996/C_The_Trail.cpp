#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long t;
    cin >> t;

    while (t--) {
        long long n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        vector<vector<long long>> A(n, vector<long long>(m, 0));
        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }

        long long x = 0, y = 0; // Starting at top-left corner
        for (char move : s) {
            if (move == 'D') {
                long long row_sum = 0;
                for (long long j = 0; j < m; j++) {
                    if (j != y) row_sum += A[x][j];
                }
                A[x][y] = -row_sum;
                x++;
            } else if (move == 'R') {
                long long col_sum = 0;
                for (long long i = 0; i < n; i++) {
                    if (i != x) col_sum += A[i][y];
                }
                A[x][y] = -col_sum;
                y++;
            }
        }

        // Set the bottom-right corner value
        long long final_sum = 0;
        for (long long i = 0; i < n - 1; i++) {
            final_sum += A[i][m - 1];
        }
        A[n - 1][m - 1] = -final_sum;

        // Output the restored grid
        for (const auto &row : A) {
            for (long long val : row) {
                cout << val << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
