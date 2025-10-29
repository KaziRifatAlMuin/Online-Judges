#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin >> s;
    ll ans = 1, cur = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i-1] == s[i]) cur++;
        else cur = 1;
        ans = max(ans, cur);
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
// https://cses.fi/problemset/task/1069