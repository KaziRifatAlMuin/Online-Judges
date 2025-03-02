#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cin >> k;
    while(k--){
        int l, r; cin >> l >> r;
        int lb = lower_bound(v.begin(), v.end(), l) - v.begin();
        int ub = upper_bound(v.begin(), v.end(), r) - v.begin();
        cout << ub - lb << " ";
    }
    cout << "\n";
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
// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  