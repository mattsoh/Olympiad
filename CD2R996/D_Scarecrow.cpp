#include <bits/stdc++.h>
using namespace std;

bool can_reach(const vector<long long>& a, long long n, long long k, long long l, long long T) {
    long long crow_pos = 0;
    for (auto pos : a) {
        long long max_pos = pos + T;
        if (max_pos < crow_pos) continue; 
        if (pos - T <= crow_pos) {
            crow_pos += k;
            if (crow_pos >= l) return true;
        }
    }
    return crow_pos >= l;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        long long n,k,l; cin >> n >> k >> l;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        sort(a.begin(), a.end());
        long long left = 0, right = 2LL*1000000000, ans = right;
        while(left <= right){
            long long mid = (left+right)/2;
            if(can_reach(a, n, k, l, mid)){
                ans = mid; 
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        cout << 2LL*ans << "\n";
    }
    return 0;
}