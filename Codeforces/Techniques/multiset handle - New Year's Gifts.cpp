#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 2e9 + 5;

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    multiset <ll> st;
    for(int i = 0; i < m; i++){
        ll a; cin >> a;
        st.insert(a);
    }
    vector <ll> x(n), y(n), z(n);
    vector <pair<ll,ll>> v;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> z[i];
        k -= y[i];
        z[i] -= y[i];
        v.push_back({z[i], x[i]});
    }
    sort(v.rbegin(), v.rend());
    vector <bool> mark(n);
    for(int i = 0; i < n; i++){
        if(!st.empty()){
            auto it = st.lower_bound(v[i].second);
            if(it != st.end()){
                mark[i] = true;
                st.erase(it);
                ans++;
            }
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(!mark[i]){
            if(v[i].first <= k){
                k -= v[i].first;
                ans++;
            }
        }
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
// https://codeforces.com/contest/2182/problem/E