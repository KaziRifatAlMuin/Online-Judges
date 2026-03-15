#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

void solve(){
    ll n;
    cin >> n;
    vector <ll> v(n), odd, even, ans(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] & 1) odd.push_back(v[i]);
        else even.push_back(v[i]);
    }
    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());
    ll odd_cnt = odd.size(), even_cnt = even.size();
    ll even_sum = 0;
    if(even_cnt == 0){
        for(int i = 0; i < n; i += 2) ans[i] = odd[0];
    }
    else if(odd_cnt > 0 && even_cnt > 0){
        ll odd_max = odd[0], even_min = even.back();
        ans[0] = odd_max;
        ll ev = 0, i = 1;
        for(; i < n && ev < even_cnt; i++, ev++){
            ans[i] = ans[i-1] + even[ev];
        }
        ll sum = ans[i-1], j = 1;
        while(i < n){
            ans[i] = (j & 1) ? sum - even_min : sum;
            i++, j++;
        }
        if(odd_cnt % 2 == 0) ans[n-1] = 0;
    }
    for(auto x : ans) cout << x << " ";
    cout << "\n";
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
// https://codeforces.com/contest/2176/problem/C