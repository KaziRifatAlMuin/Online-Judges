#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    bool ok = false;
    for(ll x = 1; x <= n; x *= a){
        if(x % b == n % b) {
            ok = true;
            break;
        }
        if(a == 1) break;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
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
// https://codeforces.com/problemset/problem/1542/B