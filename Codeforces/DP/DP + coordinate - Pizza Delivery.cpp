#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = 1e18;

void solve(){
    ll n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    vector <ll> xx(n), yy(n);
    map <ll, vector<ll>> xy;
    for(int i = 0; i < n; i++) cin >> xx[i];
    for(int i = 0; i < n; i++) cin >> yy[i];
    for(int i = 0; i < n; i++){
        xy[xx[i]].push_back(yy[i]);
    }
    ll m = xy.size();
    ll dp[m+2][2];
    for(int i = 0; i <= m; i++) dp[i][0] = dp[i][1] = 1e18;
    dp[0][0] = dp[0][1] = 0;
    ll i = 1, lastx = ax, prevminy = ay, prevmaxy = ay;
    for(auto [x,vy] : xy){
        ll maxy = 0, miny = 2e9;
        for(auto y : vy){
            maxy = max(maxy, y);
            miny = min(miny, y);
        }
        ll width = maxy - miny;
        ll dist = x - lastx;
        // dp[i][0] = finish at maxy (top)
        dp[i][0] = dist + width +
            min(dp[i-1][0] + abs(prevmaxy - miny), dp[i-1][1] + abs(prevminy - miny));
        // dp[i][1] = finish at miny (bottom)
        dp[i][1] = dist + width +
            min(dp[i-1][0] + abs(prevmaxy - maxy), dp[i-1][1] + abs(prevminy - maxy));
        prevminy = miny, prevmaxy = maxy, lastx = x; i++;
    }
    dp[i][0] = dp[i][1] = (bx - lastx) + 
        min(dp[i-1][0] + abs(prevmaxy - by), dp[i-1][1] + abs(prevminy - by));
    cout << dp[i][0] << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/2193/F