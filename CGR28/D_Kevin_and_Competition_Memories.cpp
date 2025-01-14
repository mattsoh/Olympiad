#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to calculate the minimum sum of Kevin's ranks for each k
vector<int> solve_case(int n, int m, vector<int>& a, vector<int>& b) {
    // Sort the ratings of participants and the difficulties of problems
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Precompute the number of problems each participant can solve
    vector<int> solves(n);
    for (int i = 0; i < n; i++) {
        solves[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    // Result to store the minimum sum of Kevin's ranks for each k
    vector<int> result;

    // Iterate over each k from 1 to m
    for (int k = 1; k <= m; k++) {
        int num_contests = m / k;  // number of contests with k problems
        int total_rank = 0;

        // Calculate Kevin's rank in each contest
        for (int i = 0; i < num_contests; i++) {
            int contest_start = i * k;
            int contest_end = contest_start + k;

            // Find out how many participants can solve more problems than Kevin
            int count_more_than_kevin = 0;
            for (int solve : solves) {
                if (solve > solves[0]) {
                    count_more_than_kevin++;
                }
            }
            total_rank += count_more_than_kevin;
        }

        result.push_back(total_rank);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        // Solve the case and print the result
        vector<int> result = solve_case(n, m, a, b);
        for (int i = 0; i < m; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
