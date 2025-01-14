#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r = 0;
ll a,c,m;
ll cc = 0; // part b
map<pair<ll,ll>,bool>grid;
#define fi first
#define se second
bool valid_pos(pair<ll,ll> coor, bool vert, ll len){
    if (vert){
        if (coor.se + len > 10) return false;
        for (ll i = coor.se;i<coor.se+len;i++){
            pair<ll,ll> newcoor = {coor.fi, i};
            for (ll x = -1;x<=1;x++){
                for (ll y = -1;y<=1;y++){
                    if (grid[{newcoor.fi + x, newcoor.se + y}]){
                        // cout<<coor.fi<<' '<<coor.se<<' '<<vert<<' '<<len<<"fail"<<endl;
                        return false;
                    }
                }
            }
        }
        for (ll i = coor.se; i< coor.se+len;i++){
            grid[{coor.fi,i}] = true;
        }
        cout<<coor.fi<<' '<<coor.se<<' '<<'V'<<endl;
    } else{
        if (coor.fi + len > 10) return false;
        for (ll i = coor.fi;i<coor.fi+len;i++){
            pair<ll,ll> newcoor = {i, coor.se};
            for (ll x = -1;x<=1;x++){
                for (ll y = -1;y<=1;y++){
                    if (x == 0 && y == 0) continue;
                    if (grid[{newcoor.fi + x, newcoor.se + y}]){
                        // cout<<coor.fi<<' '<<coor.se<<' '<<vert<<' '<<len<<"fail"<<endl;
                        return false;
                    }
                }
            }
        }
        for (ll i = coor.fi; i< coor.fi+len;i++){
            grid[{i,coor.se}] = true;
        }
        cout<<coor.fi<<' '<<coor.se<<' '<<'H'<<endl;
    }
    return true;
}
void place_ship(ll len){
    bool place = false;
    while (!place){
        r = (a*r+c)%m;
        pair<ll,ll> coor = {r%10,(r%100)/10};
        
        // if (cc++ < 4) cout<<"moving to"<<coor.fi<<coor.se<<endl; // part b
        r = (a*r+c)%m;
        if (valid_pos(coor,r%2,len)) break;
    }

}
int main(){
   cin>>a>>c>>m;
   ll add_ships[10] = {4,3,3,2,2,2,1,1,1,1};
   for (auto ship:add_ships){
        place_ship(ship);
   } 
}
