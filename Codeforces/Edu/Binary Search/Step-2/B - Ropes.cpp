#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define eps 1e-8

void solve() {
    ll n, k;
    cin >> n >> k;
    vector <ld> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ld low = eps, high = 2e7, ans = 0;
    while(high - low > eps){ // TTTTTFFFFF
        ld mid = low + (high - low) / 2.0;
        bool ok = false;
        ll cnt = 0;
        for(int i = 0; i < n; i++){
            ld pc = v[i] / mid;
            cnt += (ll) pc;
        }
        if(cnt >= k) ok = true;
        if(ok) ans = mid, low = mid;
        else high = mid;
    }
    cout << fixed << setprecision(8) << ans << "\n";
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
// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   