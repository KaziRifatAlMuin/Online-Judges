#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    map <int, int> mp;
    ll one = 0, extra = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    for(auto [x,y] : mp) {
        if(y == 1) one++;
        else extra++;
    }
    cout << ((one + 1) / 2) * 2 + extra << "\n";
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
// https://codeforces.com/contest/2042/problem/B