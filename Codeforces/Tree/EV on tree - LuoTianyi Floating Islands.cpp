#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

vector <vector<int>> G;
ll up = 0, n, k;

ll power(ll a, ll b) {
    ll result = 1;
    a = a % mod;
    while (b > 0){
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1ll;
    }
    return result;
}

inline ll modinv(ll a) { return power(a, mod - 2); }


ll nc2(ll n){
    return ((n * (n-1)) / 2) % mod;
}

ll dfs(ll u, ll par = -1){
    ll child = 0, parent = 0, bad = 0;
    for(auto v: G[u]){
        if(v == par) continue;
        ll cnt = dfs(v, u);
        if(cnt >= 2) bad = (bad + nc2(cnt)) % mod;
        child += cnt;
    }
    parent = n - child - 1;
    if(parent >= 2) bad = (bad + nc2(parent)) % mod;
    ll all = nc2(n);
    ll good = ((all - bad) % mod + mod) % mod;
    up = (up + good) % mod;
    child++; // self
    return child;
}

void solve(){
    cin >> n >> k;
    G.assign(n+1, {});
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(k != 2){
        cout << 1 << "\n";
        return;
    }
    dfs(1);
    ll down = nc2(n);
    // cout << up << " " << down << "\n";
    ll ans = (up * modinv(down)) % mod;
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
// https://codeforces.com/problemset/problem/1824/B1