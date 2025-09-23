#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    ll a = 0, b = n+1, l = m, r = m;
    bool idk = false;
    while(q--){
        ll x; cin >> x;
        if(!a){
            if((x >= l && x <= r) || x >= b) a = 1;
        }
        else if(x > a) a = min(a+1, n);
        if(b > n){
            if((x >= l && x <= r) || x <= a) b = n;
        }
        else if(x < b) b = max(b-1, 1ll);
        if(l == r && l == x) idk = true, l = 0, r = -1;
        if(!idk){
            if(x < l) l = max(l-1, 1ll);
            if(x > r) r = min(r+1, n);
        }
        ll ans = r - l + 1;
        if(a >= b) ans = n;
        else if(!idk){
            ans += min(a, l - 1);
            ans += (n - max(b, r+1) + 1);
        }
        else ans = a + (n - b + 1);
        cout << ans << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2051/problem/F