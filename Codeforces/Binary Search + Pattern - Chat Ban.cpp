#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, x;
    cin >> n >> x;
    ll low = 1, high = 2*n - 1, ans = 0;
    while(low <= high){ // TTTTTTFFFFFF
        ll mid = low + (high - low) / 2;
        ll msg = 0, k = mid;
        if(mid >= n) {
            msg += (n * (n + 1)) / 2;
            k -= n;
            ll a = n-1, b = n-1 - k;
            msg += (a * (a + 1) / 2) - (b * (b + 1) / 2);
        }
        else{
            msg = (k * (k + 1)) / 2;
        }
        // cout << mid << " " << msg << "\n";
        if(msg == x) {ans = mid; break;}
        else if(msg < x) ans = min(2*n - 1, mid + 1), low = mid + 1;
        else high = mid - 1;
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
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1612/problem/C