#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector <ll> v(n);
    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i & 1) sum2 += v[i];
        else sum1 += v[i];
    }
    ll ans = sum1 - sum2;
    ll f1 = ans;
    f1 = ans + n - 1 - (n % 2 == 0);
    ll max_odd = -2e17, min_even = 2e17;
    for(int i = 0; i < n; i++){
        // Swap Contribution: 2 * (y - x) + abs(j - i)
        if(i & 1){
            f1 = max(f1, ans + i + 2 * v[i] - min_even); // taking from odd
            max_odd = max(max_odd, 2 * v[i] - i);
        }
        else{
            f1 = max(f1, ans + i - 2 * v[i] + max_odd); // replacing current even
            min_even = min(min_even, i + 2 * v[i]);
        }
    }
    cout << f1 << "\n";
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
// https://codeforces.com/problemset/problem/2140/C