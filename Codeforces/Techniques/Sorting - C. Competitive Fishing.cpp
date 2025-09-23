#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    ll n, k;
    cin >> n >> k >> s;
    vector <int> diff(n);
    ll pre0 = 0, pre1 = 0;
    for(int i = n - 1; i > 0; i--){
        if(s[i] == '0') pre0++;
        else pre1++;
        diff[i] = pre1 - pre0;
    }
    sort(diff.rbegin(), diff.rend());
    ll sum = 0, ans = 1;
    for(auto x : diff){
        ans++;
        sum += x;
        if(sum >= k){
            cout << ans << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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
// https://codeforces.com/contest/2042/problem/C