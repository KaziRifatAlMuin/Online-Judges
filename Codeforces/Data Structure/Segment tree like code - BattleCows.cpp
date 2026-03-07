#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

void solve(){
    ll n, q;
    cin >> n >> q;
    vector <ll> v(1 << (n+1));
    // Build Segment Tree
    for(int i = (1 << n); i < (1 << (n+1)); i++) cin >> v[i];
    for(int i = (1 << n) - 1; i > 0; i--) v[i] = v[2*i] ^ v[2*i + 1];     
    // Update/Query
    while(q--){
        ll i, c;
        cin >> i >> c;
        i += (1 << n) - 1;
        ll ans = 0, sz = 1;
        while(i != 1){
            ll j = i ^ 1;
            if(v[j] > c || (v[j] == c && j < i)) ans += sz;
            i /= 2; sz *= 2;
            c ^= v[j];
        }
        cout << ans << "\n";   
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
// https://codeforces.com/contest/2185/problem/F