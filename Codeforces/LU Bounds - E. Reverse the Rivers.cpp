#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> b(k + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int r = 1; r <= k; r++){
            int a; cin >> a;
            if(i == 1) b[r][i] = a;
            else b[r][i] = b[r][i-1] | a;
        }
    }
    while(q--){
        int m; cin >> m;
        int l_max = 1, r_min = n;
        bool ok = true;
        for(int req = 0; req < m; req++){
            int r, c;
            char o;
            cin >> r >> o >> c;
            vector<int>& b_r = b[r];
            int l_i, r_i, pos;
            if(o == '<'){
                pos = lower_bound(b_r.begin() + 1, b_r.begin() + n + 1, c) - b_r.begin();
                l_i = 1;
                r_i = pos - 1;
            } 
            else if(o == '>'){
                pos = upper_bound(b_r.begin() + 1, b_r.begin() + n + 1, c) - b_r.begin();
                l_i = pos;
                r_i = n;
            }
            l_max = max(l_max, l_i);
            r_min = min(r_min, r_i);
        }
        if(ok && l_max <= r_min) cout << l_max << "\n";
        else cout << -1 << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2036/problem/E