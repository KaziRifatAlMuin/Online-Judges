#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

void solve(){
    int n;
    cin >> n;
    vector <ll> v(n), ans(n);
    vector <pair<ll,ll>> vv;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 1; i < n; i++) vv.push_back({abs(v[i] - v[i-1]), i-1});
    sort(vv.begin(), vv.end());
    set <ll> st;
    st.insert(0), st.insert(n-1);
    for(auto [d, i]: vv){
        auto it1 = st.upper_bound(i); it1--;
        auto it2 = st.lower_bound(i+1);
        ll l = *it1, r = *it2;
        ll cnt = 1ll * (i - l + 1) * (r - (i+1) + 1);
        ans[d] += cnt;
        st.insert(i); st.insert(i+1);
    }
    for(int i = n-2; i >= 1; i--) ans[i] += ans[i+1];
    for(int i = 1; i < n; i++) cout << ans[i] << (i == n-1 ? "\n" : " ");
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
// https://codeforces.com/contest/2184/problem/E