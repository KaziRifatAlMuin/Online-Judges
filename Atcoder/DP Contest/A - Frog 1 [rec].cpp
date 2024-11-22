#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <ll> dp, h;

ll run(ll i) {
    if(i <= 2) return abs(h[i] - h[0]);
    if(dp[i] != -1) return dp[i];
    ll ans = min(run(i - 1) + abs(h[i] - h[i-1]), run(i - 2) + abs(h[i] - h[i-2]));
    return dp[i] = ans;
}

void solve() {
    int n;
    cin >> n;
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
