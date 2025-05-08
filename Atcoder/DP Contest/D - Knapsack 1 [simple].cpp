#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector <ll> w(n), p(n), dp(k+1, 0);
    for(int i = 0; i < n; i++) cin >> w[i] >> p[i];
    for(int i = 0; i < n; i++){
        for(int j = k; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
            // reverse cause dp[j - w[i]] is from previous row
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
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
// https://atcoder.jp/contests/dp/tasks/dp_d