#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    ll x = 0, xplusy = 0;
    for(int i = 0; i < n; i++){
        ll xx, yy;
        cin >> xx >> yy;
        x ^= xx; // must exactly one be odd
        xplusy ^= (xx + yy); // must be exactly one odd
    }
    cout << x << " " << xplusy - x << "\n";
}  

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2096/problem/D