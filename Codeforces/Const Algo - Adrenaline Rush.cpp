#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector <int> c(n+1);
    vector <bool> istaken(n+1, false);
    vector <pair<int, int>> ans;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = n; i >= 1; i--){
        int init = c[i], p = c[i];
        int final = i;
        for(int q = init - 1; q >= 1; q--){
            if(!istaken[q]) ans.push_back({p, q});
        }
        istaken[p] = true;
        for(int q = 1; q <= n; q++){
            if(!istaken[q]) ans.push_back({q, p});
        }
    }
    cout << ans.size() << "\n";
    for(auto [x, y] : ans){
        cout << x << " " << y << "\n";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/2052/A                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  