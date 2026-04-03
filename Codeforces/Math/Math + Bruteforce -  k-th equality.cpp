#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll small[] = {0, 1, 10, 100, 1000, 10000, 100000};
ll big[] = {0, 9, 99, 999, 9999, 99999, 999999};

void solve() {
    ll A, B, C, k;
    cin >> A >> B >> C >> k;
    ll cnt = 0;
    for(ll a = small[A]; a <= big[A]; a++){
        ll b_min = max(small[B], small[C] - a);
        ll b_max = min(big[B], big[C] - a);
        ll rem = b_max - b_min + 1;
        if(rem < 0) continue;
        else if(rem + cnt >= k){
            ll b = b_min + (k - cnt) - 1;
            cout << a << " + " << b << " = " << a+b << "\n";
            return;
        }
        else cnt += rem;
    }
    cout << -1 << "\n";
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
// https://codeforces.com/contest/1835/problem/A