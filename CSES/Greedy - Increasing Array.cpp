#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll ans = 0;
    for(int i = 1; i < n; i++){
        if(v[i] < v[i-1]){
            ans += (v[i-1] - v[i]);
            v[i] = v[i-1];
        }
    }
    cout << ans << "\n";
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
// https://cses.fi/problemset/task/1094