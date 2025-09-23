#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n - 1; i++){
        int a = s[i] - '0';
        int bx = -100, jx = i;
        for(int j = 1; j < 10 && i + j < n; j++){
            int b = s[i+j] - '0' - j;
            if(b > bx){
                bx = b;
                jx = j;
            }
        }
        if(bx > a){
            // cout << b << " " << a << " " << j << " ";
            char c = bx + '0';
            for(int k = i + jx; k > i && i + jx < n; k--){
                s[k] = s[k-1];
            }
            s[i] = c;
        }
        // cout << s << " | ";
    }
    cout << s << "\n";
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
// https://codeforces.com/contest/2050/problem/D