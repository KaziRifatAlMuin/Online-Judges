#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    if(n == 1){
        cout << 1 << "\n" << 1 << "\n";
    }
    else if(k == 1 || k == n){
        cout << -1 << "\n";
    }
    else{
        cout << 3 << "\n";
        if(k & 1) cout << 1 << " " << k - 1 << " " << k + 2 << "\n";
        else cout << 1 << " " << k << " " << k + 1 << "\n";
    }
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
// https://codeforces.com/contest/2032/problem/B