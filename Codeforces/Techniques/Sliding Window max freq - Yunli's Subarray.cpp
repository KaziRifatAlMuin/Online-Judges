#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;

void solve(){
    ll n, k, q;
    cin >> n >> k >> q;
    vector <ll> v(n), ans(n+1);
    for(int i = 0; i < n; i++) cin >> v[i];
    map <ll,ll> mp;
    multiset <ll> st;
    for(int i = 0; i < n; i++){
        // Sliding window for max frequency
        ll add = v[i] - i;
        if(mp.find(add) != mp.end()){
            if(st.find(mp[add]) != st.end()) st.erase(st.find(mp[add]));
            mp[add]++;
            st.insert(mp[add]);
        }
        else mp[add] = 1, st.insert(1);
        if(i >= k){
            ll j = i - k;
            ll rem = v[j] - j;
            if(st.find(mp[rem]) != st.end()) st.erase(st.find(mp[rem]));
            mp[rem]--;
            st.insert(mp[rem]);
        }
        if(i >= (k-1)) ans[i] = *st.rbegin();
    }
    while(q--){
        ll l, r;
        cin >> l >> r;
        cout << (k - ans[r-1]) << "\n";
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
// https://codeforces.com/problemset/problem/2009/G1