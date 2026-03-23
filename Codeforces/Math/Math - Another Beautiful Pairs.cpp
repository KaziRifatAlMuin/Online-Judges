#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector <ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        for(ll d = a[i]; d <= min(n, a[i] * a[i]); d += a[i]){ // makes it O(n * sqrt(n))
            ll j1 = i + d, j2 = i - d;
            if(j1 < n && a[j1] * a[i] == d) ans++;
            if(j2 >= 0 && a[j2] * a[i] == d && a[i] != a[j2]) ans++;
        }
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
// https://codeforces.com/problemset/problem/2196/B