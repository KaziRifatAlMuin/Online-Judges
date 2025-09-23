#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    int xora = 0, xorb = 0;
    for(int i = 0; i < n; i++) cin >> a[i], xora ^= a[i];
    for(int i = 0; i < m; i++) cin >> b[i], xorb ^= b[i];
    if(xora != xorb){
        cout << "NO\n"; return;
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0){
                if(j == 0) cout << (xora ^ b[0] ^ a[0]) << " ";
                else cout << b[j] << " ";
            }
            else if(j == 0) cout << a[i] << " ";
            else cout << 0 << " ";
        }
        cout << "\n";
    }  
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1016/problem/D