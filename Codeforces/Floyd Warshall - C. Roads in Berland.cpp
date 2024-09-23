#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n, inf = 1e17;
    cin >> n;
    ll dist[n+1][n+1];
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            cin >> dist[i][j];
        }
    }
    int road; 
    cin >> road;
    for(int q = 0; q < road; q++){
        ll u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = min(dist[u][v], w);
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][u] + dist[u][j]);
            }
        }
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][v] + dist[v][j]);
            }
        }

        ll sum = 0;
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= n; j++){
                sum += dist[i][j];
            }
        }
        cout << sum / 2 << " ";
    }
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
// https://codeforces.com/contest/25/problem/C