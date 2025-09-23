#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n, inf = 1e17;
    cin >> n;
    ll dist[n+1][n+1];
    vector <ll> v(n), ans, added(n+1);
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            cin >> dist[i][j];
        }
    }
    for(int i = 0; i < n; i++) cin >> v[i];
    reverse(v.begin(), v.end());
    for(auto k : v){
        added[k] = true;
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
        ll sum = 0;
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= n; j++){
                if(added[i] && added[j]) sum += dist[i][j];
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
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
// https://codeforces.com/contest/295/problem/B