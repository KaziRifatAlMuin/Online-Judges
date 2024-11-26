#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll> a, b, c;
vector<vector<ll>> dp;

ll run(int i, int prev) {
    if (i == n) return 0;
    if (prev >= 0 && dp[i][prev] != -1) return dp[i][prev];
    if (prev == 0) return dp[i][prev] = max(run(i + 1, 1) + b[i], run(i + 1, 2) + c[i]);
    if (prev == 1) return dp[i][prev] = max(run(i + 1, 0) + a[i], run(i + 1, 2) + c[i]);
    if (prev == 2) return dp[i][prev] = max(run(i + 1, 0) + a[i], run(i + 1, 1) + b[i]);
    return max({run(i + 1, 0) + a[i], run(i + 1, 1) + b[i], run(i + 1, 2) + c[i]});
}

void solve() {
    cin >> n;
    a.resize(n), b.resize(n), c.resize(n);
    dp.assign(n, vector<ll>(3, -1));
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    cout << run(0, -1) << "\n";
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
// https://atcoder.jp/contests/dp/tasks/dp_c