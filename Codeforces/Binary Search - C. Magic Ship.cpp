#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll n; cin >> n;
    string s; cin >> s;
    ll ans = -1, low = 0, high = 1e18;
    ll xp = 0, yp = 0, x, y;
    for(auto ch : s){
        if(ch == 'U') yp++;
        else if(ch == 'D') yp--;
        else if(ch == 'L') xp--;
        else if(ch == 'R') xp++;
    }
    while(low <= high){ // FFFFFTTTTT
        ll mid = low + (high - low) / 2;
        ll t = mid / n;
        ll extra = mid % n;
        x = xp * t; y = yp * t;
        for(int i = 0; i < extra; i++){
            if(s[i] == 'U') y++;
            if(s[i] == 'D') y--;
            if(s[i] == 'R') x++;
            if(s[i] == 'L') x--;
        }
        ll x3 = x1 + x, y3 = y1 + y;
        ll dis = abs(x3 - x2) + abs(y3 - y2);
        if(dis <= mid) ans = mid, high = mid - 1;
        else low = mid + 1; 
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}