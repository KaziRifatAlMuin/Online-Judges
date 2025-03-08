#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector <ll> v(n), pre(n+1), twosuff(n+1);
    ll ans = 0, sum = 0, zero = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        pre[i+1] = pre[i] + v[i];
        sum += v[i];
    }
    if(sum % 3 != 0) cout << 0 << "\n";
    else{
        ll p = sum / 3, q = sum * 2 / 3;
        twosuff[n] = twosuff[n] == q ? 1 : 0;
        for(int i = n - 1; i >= 1; i--){
            if(pre[i] == q) twosuff[i] = twosuff[i+1] + 1;
            else twosuff[i] = twosuff[i+1];
        }
        for(int i = 1; i <= n; i++){
            if(pre[i] == p) ans += twosuff[i];
            if(pre[i] == 0) zero++;
        }
        if(p == q) cout << max(0ll, (zero - 1) * (zero - 2) / 2) << "\n";
        else cout << ans << "\n";
    }
}

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
// https://codeforces.com/problemset/problem/466/C