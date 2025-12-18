#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 501;

int dp[502][502][512];

int n, p, m;

int run(int cur, int rem, int x){
    if(rem == 0) return x == 0;
    if(cur > rem) return 0;
    if(dp[cur][rem][x] != -1) return dp[cur][rem][x];
    int ans = run(cur+1, rem, x); // skip current number
    ans = (ans + run(cur, rem - cur, x ^ cur)) % m; // take (unbounded)
    return dp[cur][rem][x] = ans;
}

void solve() {
    cin >> n >> p >> m;
    memset(dp, -1, sizeof(dp));
    cout << run(1, n-p, p) << "\n";
}

// If bounded, then take transition cur+1 instead cur

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
// https://vjudge.net/problem/QOJ-7802