#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector <ll> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    x.push_back(1e17);
    ll ans = 0;
    ll low = 0, high = x[1] - x[0];
    for(int i = 1; i < n; i++){
        ll d = x[i] - x[i-1];
        ll nlow = d - high;
        ll nhigh = d - low;
        nhigh = min(nhigh, x[i+1] - x[i]);
        if(nlow < x[i+1] - x[i]) ans++;
        else nlow = 0;
        low = nlow, high = nhigh;
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
// https://codeforces.com/problemset/problem/2180/D