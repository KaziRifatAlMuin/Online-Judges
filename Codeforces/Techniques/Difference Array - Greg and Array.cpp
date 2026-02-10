#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector <ll> v(n+2), freq(m+2), diff(n+2);
    vector <tuple<ll,ll,ll>> op;
    op.push_back({0,0,0});
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= m; i++) {
        ll l, r, d;
        cin >> l >> r >> d;
        op.push_back({l, r, d});
    }
    while(k--){
        ll x, y;
        cin >> x >> y;
        freq[x]++;
        freq[y+1]--;
    }
    for(int i = 1; i <= m; i++) freq[i] = freq[i] + freq[i-1];
    for(int i = 1; i <= m; i++){
        auto [l, r, d] = op[i];
        diff[l] += (d * freq[i]);
        diff[r+1] -= (d * freq[i]);
    }
    for(int i = 1; i <= n; i++) diff[i] = diff[i] + diff[i-1];
    for(int i = 1; i <= n; i++) cout << v[i] + diff[i] << (i == n ? "\n" : " ");
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
// https://codeforces.com/contest/295/problem/A