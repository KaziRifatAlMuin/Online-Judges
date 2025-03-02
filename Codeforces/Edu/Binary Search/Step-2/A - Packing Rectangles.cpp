#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll w, h, n;
    cin >> w >> h >> n;
    ll low = 1, high = 1e18, ans = 0;
    while(low <= high){ // FFFFTTTTT
        ll mid = low + (high - low) / 2;
        bool ok = false;
        ll max_row = mid / h;
        ll max_col = mid / w;
        if(max_col != 0 && max_row >= (n + max_col - 1) / max_col) ok = true;
        if(ok) ans = mid, high = mid - 1;
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
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}     
// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               