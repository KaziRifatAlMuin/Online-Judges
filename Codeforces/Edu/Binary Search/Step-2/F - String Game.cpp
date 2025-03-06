#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int low = 0, high = n - m, ans = 0;
    while(low <= high){ // TTTTTFFFFF
        int mid = low + (high - low) / 2;
        string t = s;
        bool ok = false;
        for(int i = 0; i < mid; i++){
            t[v[i] - 1] = '#';
        }
        for(int i = 0, j = 0; i < m && j < n; j++){
            if(t[j] == p[i]) i++;
            if(i == m) ok = true;
            // cout << "(" << i << "," << j << ")\n";
        }
        // cout << mid + 1 << " " << ok << "\n";
        if(ok) ans = mid, low = mid + 1;
        else high = mid - 1;
    }
    cout << ans << "\n";
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
// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F
