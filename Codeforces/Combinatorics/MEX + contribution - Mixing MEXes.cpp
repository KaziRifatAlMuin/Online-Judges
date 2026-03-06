#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;

void solve(){
    ll n, cnt = 0;
    cin >> n;
    vector <vector<ll>> v(n);
    map <ll,ll> mp;
    for(int i = 0; i < n; i++){
        ll m;
        cin >> m;
        for(int j = 0; j < m; j++){
            ll x; cin >> x;
            v[i].push_back(x);
            cnt++;
            mp[x]++;
        }
        sort(v[i].begin(), v[i].end());
    }
    vector <ll> mex(n), mex2(n);
    for(int i = 0; i < n; i++){
        ll m = 0;
        for(auto x : v[i]){
            if(x == m) m++;
            else if(x > m) break;
        }
        mex[i] = m;
        m++;
        for(auto x : v[i]){
            if(x == m) m++;
            else if(x > m) break;
        }
        mex2[i] = m;
    }
    ll mexsum = 0;
    for(int i = 0; i < n; i++) mexsum += mex[i];
    ll ans = cnt * (n-1) * mexsum;
    for(int i = 0; i < n; i++){
        map <ll, ll> freq;
        for(auto x : v[i]) freq[x]++;
        for(auto x : v[i]){
            ll d = 0;
            if(x < mex[i]){
                if(freq[x] == 1) d = mex[i] - x;
                ans -= (n-1) * d;
            }
        }
    }
    for(int i = 0; i < n; i++) ans += (mex2[i] - mex[i]) * mp[mex[i]];
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
// https://codeforces.com/problemset/problem/2185/G