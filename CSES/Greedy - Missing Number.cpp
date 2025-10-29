#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, a, sum = 0;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> a;
        sum += a;
    }
    cout << (n * (n+1) / 2) - sum << "\n";
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
// https://cses.fi/problemset/task/1083