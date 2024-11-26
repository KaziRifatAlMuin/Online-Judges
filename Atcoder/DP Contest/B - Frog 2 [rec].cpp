#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <ll> dp, h;
int n, k;

ll run(ll i) {
    if(i <= k) return abs(h[i] - h[0]);
    if(dp[i] != -1) return dp[i];
    ll ans = run(i - 1) + abs(h[i] - h[i-1]);
    for(int j = i - 2; j > 0 && j >= i - k; j--) ans = min(ans, run(j) + abs(h[i] - h[j]));
    return dp[i] = ans;
}

void solve() {
    int n;
    cin >> n >> k;
    h.resize(n);
    dp.resize(n, -1);
    for(int i = 0; i < n; i++) cin >> h[i];
    cout << run(n - 1) << "\n";
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
https://atcoder.jp/contests/dp/tasks/dp_b