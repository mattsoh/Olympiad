#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 10;
struct Point {
    ll x, y;
};
vector<Point> points[maxn];
vector<ll> tree[maxn];
double areaa[maxn];

bool isInside(vector<Point>& polygon,const Point p) {
    int n = polygon.size();
    bool inside = false;

    for (int i = 0, j = n - 1; i < n; j = i++) {
        // Get vertices of the polygon edge
        const Point& xv1 = polygon[i];
        const Point& v2 = polygon[j];

        // Check if point is within y-bounds and to the left of the edge
        if (((v1.y > p.y) != (v2.y > p.y)) && 
            (p.x < (v2.x - v1.x) * (p.y - v1.y) / (v2.y - v1.y) + v1.x)) {
            inside = !inside;
        }
    }

    return inside;
}
bool cmp(vector<Point> a, vector<Point> b){
    for (auto i: a){
        if (!isInside(b,i)) return false;
    }
    return true;
}
double polygonArea(vector<Point> poly) {
    int n = poly.size();
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n; 
        area += poly[i].x * poly[next].y;
        area -= poly[i].y * poly[next].x;
    }  
    return fabs(area) / 2.0;
}
int main(){
    if (fopen("PAINT.INP", "r")){
        freopen("PAINT.INP", "r", stdin);
        freopen("PAINT.OUT", "w", stdout);
    }
    ll W,H,n,m,q; cin>>W>>H>>n>>m>>q;
    points[0] = {{0,0},{W,0},{W,H},{0,H}};
    for (ll i = 1; i<=n;i++){
        vector<Point> poly;
        for (ll j = 0; j<m;j++){
            ll x,y;cin>>x>>y;
            poly.push_back({x,y});
        }
        points[i] = poly;
        areaa[i] = polygonArea(poly);
        ll idx = 0;
        while (true) {
            bool found = false;
            for (auto nxt: tree[idx]){
                if (cmp(poly,points[nxt])){
                    idx = nxt;
                    found = true;
                    break;
                }
            }
            if (!found) break;
        }
        tree[idx].push_back(i);
    }
    for(ll i = 0; i <= n; i++){
        cout << "Node " << i << ": ";
        for(auto child : tree[i]){
            cout << child << " ";
        }
        cout << endl;
    }
    for (ll i = 0; i<q;i++){
        ll x,y;cin>>x>>y;
        ll cnt = 0;
        ll idx = 0;
        while (true) {
            bool found = false;
            for (auto nxt: tree[idx]){
                if (isInside(points[nxt],{x,y})){
                    idx = nxt;
                    found = true;
                    break;
                } else {
                    cout<<x<<' '<<y<<" not in "<<idx<<endl;
                }
            }
            if (!found) break;
        }
        double area = areaa[idx];
        for (auto nxt: tree[idx]){
            area -= areaa[nxt];
        }
        cout<<fixed<<setprecision(1)<<area<<endl;
    }
}