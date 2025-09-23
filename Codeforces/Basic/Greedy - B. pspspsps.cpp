#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    bool ok = true;
    string s;
    int n; cin >> n;
    cin >> s;
    bool pp = false, ss = false;
    for(int i = 1; i < n - 1; i++){
        if(s[i] == 's') ss = true;
        if(s[i] == 'p') pp = true;
    }
    if(ss && pp) ok = false;
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'p') a++;
        if(s[i] == 's'){
            if(a != 0) ok = false;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
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
// https://codeforces.com/contest/2049/problem/B