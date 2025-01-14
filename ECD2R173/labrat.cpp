#include <bits/stdc++.h>

using namespace std;

// make sure modify 0LL + , 1LL * when remove define
#define int long long
#define _3bkarm cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

void get_shit_done() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> l(m);
    for (int i = 0; i < m; ++i) {
        cin >> l[i];
        --l[i];
    }

    vector<bool> can(n);
    for (int i = 0, x; i < k; ++i) {
        cin >> x;
        --x;
        can[x] = true;
    }

    int lose = 0;
    for (int i = 0; i < n; ++i) {
        lose += (not can[i]);
    }

    for (int i = 0; i < m; ++i) {
        if (lose > 1) {
            cout << 0;
            continue;
        }
        if (lose == 0) {
            cout << 1;
            continue;
        }
        if ( not can[l[i]] ) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << '\n';
}

signed main() {
    _3bkarm

    int ts = 1;
    cin >> ts;
    while (ts--) {
        get_shit_done();
    }

    return 0;
}