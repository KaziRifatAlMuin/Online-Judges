#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

void solve(){
    ll x, y, k;
    cin >> x >> y >> k;
    ll ans = -1, low = 1, high = 1e12;
    while(low <= high){ // FFFFTTTTT
        ll mid = low + (high - low) / 2;
        ll rem = mid;
        for(int i = 0; i < x; i++) rem -= (rem / y);
        if(rem > k) high = mid - 1;
        else if(rem == k) ans = mid, high = mid - 1;
        else low = mid + 1;
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
// https://codeforces.com/contest/2169/problem/D1