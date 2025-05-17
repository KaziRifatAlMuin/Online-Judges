#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

ll run(ll n, ll m, ll r, ll c){
    if(n * m == 1) return 0;
    set <tuple<ll,ll,ll>> st;
    st.insert({n * c, n, c});
    st.insert({(n - r + 1) * m, (n - r + 1), m});
    st.insert({n * (m - c + 1), n, (m - c + 1)});
    st.insert({r * m, r, m});
    ll ans = 1e9;
    for(auto [x, a, b] : st){
        ll cnt = 0;
        // cout << a << " " << b << " ";
        if(a < 1 && b < 1) continue;
        while(a > 1) a = (a + 1) / 2, cnt++;
        while(b > 1) b = (b + 1) / 2, cnt++;
        ans = min(ans, cnt);
        // cout << cnt << "\n"; 
    }
    return 1 + ans;
}

void solve(){
    ll n, m, r, c;
    cin >> n >> m >> r >> c;
    cout << run(n,m,r,c) << "\n";
}
    

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2109/problem/B