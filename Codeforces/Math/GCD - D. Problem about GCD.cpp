#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll l, r, g;
    cin >> l >> r >> g;
    ll a = (l / g + (l % g != 0)) * g;
    ll b = (r / g) * g;
    ll aa = -1, bb = -1, diff = -1;
    if(a > b) {cout << "-1 -1\n"; return;}
    for(int i = 0; i < 20; i++){
        if(a + i * g > b) continue;
        for(int j = 0; j < 20; j++){
            ll x = a + i * g, y = b - j * g;
            if(__gcd(x, y) == g && x <= y && x >= l && x <= r && y >= l && y <= r){
                if(abs(x - y) > diff){
                    aa = x;
                    bb = y;
                    diff = abs(x - y);
                }
            }
        }
    }
    cout << aa << " " << bb << "\n";
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
// https://codeforces.com/contest/2043/problem/D