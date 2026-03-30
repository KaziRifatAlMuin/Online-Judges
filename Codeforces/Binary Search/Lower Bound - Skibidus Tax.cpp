#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());
    a[0] = min(a[0], b[0] - a[0]);
    for(int i = 1; i < n; i++){
        ll need = a[i-1] + a[i];
        auto j = lower_bound(b.begin(), b.end(), need) - b.begin();
        if(j < m){
            ll cur = b[j] - a[i];
            if(a[i] >= a[i-1]) a[i] = min(a[i], cur);
            else a[i] = cur;
        }
    }
    bool ok = true;
    for(int i = 0; i < n-1; i++){
        if(a[i] > a[i+1]) ok = false;
    }
    // for(int i = 0; i < n; i++) cout << a[i] << " ";
    if(ok) cout << "YES\n";
    else cout << "NO\n";
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
// https://codeforces.com/problemset/problem/2065/C2