#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5, mod = 998244353;

ll dp[N][2][2], pairs[N][2][2];
vector <ll> v;

ll run(ll i, ll p1, ll p2){
    if(i <= 2) return 0;
    if(dp[i][p1][p2] != -1) return dp[i][p1][p2];
    ll res = run(i-1, p1, p2) % mod;
    if((v[i] & 1) == p2){
        ll p0 = p1 ^ p2;
        res = (res + run(i-1, p0, p1) + pairs[i-1][p0][p1]) % mod;
    }
    return dp[i][p1][p2] = res;
}

void solve(){
    ll n;
    cin >> n;
    v.resize(n+1);
    vector <ll> odd(n+1), even(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        even[i] = even[i-1] + !(v[i] & 1);
        odd[i] = odd[i-1] + (v[i] & 1);
        for(int p1 = 0; p1 < 2; p1++){
            for(int p2 = 0; p2 < 2; p2++){
                pairs[i][p1][p2] = (pairs[i-1][p1][p2] +
                                (p2 == (v[i] & 1) ? ( p1 & 1 ? odd[i-1] : even[i-1] ) : 0)) % mod;
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for(int p1 = 0; p1 < 2; p1++){
        for(int p2 = 0; p2 < 2; p2++){
            ans = (ans + run(n, p1, p2)) % mod;
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
// https://codeforces.com/problemset/problem/1912/K