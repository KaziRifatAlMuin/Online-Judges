#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector <ll> v(n);
    map <ll, ll> cnt;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    for(auto [x, y]: cnt){
        if(y % k != 0){
            cout << 0 << "\n";
            return;
        }
    }
    ll ans = 0;
    map <ll, ll> cur;
    for(int l = 0, r = 0; l <= r && r < n; r++){
        cur[v[r]]++;
        // cout << l << " " << r << "\n";
        while(cur[v[r]] > cnt[v[r]]/k){
            cur[v[l]]--;
            l++;
        }
        ans += (r - l + 1); // count subarray ending at v[r]
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
// https://codeforces.com/problemset/problem/2148/E