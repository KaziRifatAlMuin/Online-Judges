#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    while(k--){
        int x; cin >> x;
        int low = 0, high = n - 1;
        bool ok = false;
        while(low <= high){
            int mid = (high + low) / 2;
            if(v[mid] == x) {ok = true; break;}
            else if(v[mid] < x) low = mid + 1;
            else high = mid - 1;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
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
// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 