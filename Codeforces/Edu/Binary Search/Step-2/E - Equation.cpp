#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define eps 1e-8

void solve() {
    ld c;
    cin >> c;
    ld low = eps, high = 2e5, ans = 0;
    while(1){
        ld x = low + (high - low) / 2;
        ld y = x * x + sqrt(x);
        if(abs(y - c) < eps) {ans = x; break;}
        else if(y > c) high = x;
        else low = x;
    }
    cout << fixed << setprecision(10) << ans << "\n";
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
// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E