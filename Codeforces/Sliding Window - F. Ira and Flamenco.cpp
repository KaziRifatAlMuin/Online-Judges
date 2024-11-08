#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const mod = 1e9 + 7;

ll power(ll a, ll b) {
    ll result = 1;
    a = a % mod;
    while (b > 0){
        if (b & 1) result = (__int128(result) * a) % mod;
        a = (__int128(a) * a) % mod;
        b >>= 1ll;
    }
    return result;
}

inline ll modInverse(ll a) { return power(a, mod - 2); }

void solve() {
    ll n, k;
    cin >> n >> k;
    vector <int> v(n);
    map <ll,ll> mp;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v.begin(), v.end());
    ll ans = 0, window = 1;
    v.erase(unique(v.begin(), v.end()), v.end());
    ll last = 1;
    for(int i = 0; i < v.size(); i++){
        window = (((window * mp[v[i]]) % mod) * modInverse(last)) % mod;
        if(i - k + 1 >= 0 && v[i] - v[i-k+1] == k-1){
            ans = (ans + window) % mod;
        }
        if(i - k + 1 >= 0) last = mp[v[i - k + 1]];
        // cout << v[i] << " " << window << " " << ans << "\n";
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
// https://codeforces.com/problemset/problem/1833/F