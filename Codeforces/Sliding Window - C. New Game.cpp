#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector <ll> v(n);
    map <ll, ll> mp;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    vector <ll> num, cnt;
    for(auto x : mp){
        num.push_back(x.first);
        cnt.push_back(x.second);
    }
    ll m = num.size(), ans = cnt[0], sum = cnt[0], l = 0;
    for(ll r = 1; r < m; r++){
        if(num[r] - num[r-1] > 1){
            l = r;
            sum = cnt[r];
        }
        else{
            sum += cnt[r];
        }
        if(r - l + 1 > k){
            sum -= cnt[l];
            l++;
        }
        ans = max(ans, sum);
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
// https://codeforces.com/contest/2025/problem/C