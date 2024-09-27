#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    vector <ll> v(n), pre(n+1);
    ll half, kill = 0;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) pre[i+1] = pre[i] + v[i];
    half = (pre[n] + 1) / 2;
    for(int i = 1; i <= n; i++){
        if(pre[i] > half) kill++;
    }
    cout << half + kill << "\n";
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
// hthttps://codeforces.com/contest/1891/problem/C