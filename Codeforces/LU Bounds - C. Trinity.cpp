#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), pre(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        if(i > 0) pre[i-1] = v[i-1] + v[i]; 
    }
    ll ans = INT_MAX;
    for(auto x : v){
        ll a = upper_bound(pre.begin(), pre.end(), x) - pre.begin();
        ll b = n - (upper_bound(v.begin(), v.end(), x) - v.begin());
        ans = min(ans, a + b);
    }
    cout << ans << "\n";
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
// https://codeforces.com/contest/2032/problem/C