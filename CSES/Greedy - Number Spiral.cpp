#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e6 + 7;
 
void solve()
{
    ll r, c;
    cin >> r >> c;
    if(r > c){
        if(r & 1) cout << (r - 1) * (r - 1) + c << "\n";
        else cout << r * r - c + 1 << "\n";
    }
    else{
        if(c & 1) cout << c * c - r + 1 << "\n";
        else cout << (c - 1) * (c - 1) + r << "\n";
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, cs = 1, st = clock();
    cin >> t;
    while(t--){
        // cout << "Case " << cs++ << ": ";
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
