#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ask(int l, int r){
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    int n = r - l + 1;
    int target = l, mismatch = 0;
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        if(v > r || v < l) mismatch++;
        target++;
    }
    return mismatch % 2 != n % 2;
}

void solve() {
    int n; cin >> n;
    int low = 1, high = n, ans = 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        bool ok = ask(low, mid);
        if(ok) high = mid, ans = low;
        else low = mid + 1, ans = mid + 1;
        if(low == high && ok){
            ans = low;
            break;
        }
    }
    cout << "! " << ans << "\n";
    cout.flush();
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1698/problem/D