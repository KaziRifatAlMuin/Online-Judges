#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector<int>> G;
int n;
vector <ll> depth, a, sub, dp1, dp2, max_depth;

void dfs1(int u, int par = -1){
    sub[u] += a[u];
    max_depth[u] = depth[u];
    for(auto v : G[u]){
        if(v == par) continue;
        depth[v] = depth[u] + 1;
        dfs1(v, u);
        sub[u] += sub[v];
        max_depth[u] = max(max_depth[u],  max_depth[v]);
        dp1[u] += (dp1[v] + sub[v]);
    }
}

void dfs2(int u, int par = -1){
    ll f = 0, s = 0;
    for(auto v : G[u]){
        if(v == par) continue;
        if(f < max_depth[v]) s = f, f = max_depth[v];
        else if(s < max_depth[v]) s = max_depth[v];
    }
    for(auto v : G[u]){
        if(v == par) continue;
        dfs2(v, u);
        if(max_depth[v] != f) dp2[u] = max({dp2[u], dp2[v], sub[v] * (f+1-depth[v])});
        else dp2[u] = max({dp2[u], dp2[v], sub[v] * (s+1-depth[v])});
    }
}

void solve(){
    cin >> n;
    G.assign(n+1, {});
    depth.assign(n+1, 0);
    max_depth.assign(n+1, 0);
    a.assign(n+1, 0);
    sub.assign(n+1, 0);
    dp1.assign(n+1, 0);
    dp2.assign(n+1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1);
    dfs2(1);
    for(int i = 1; i <= n; i++) cout << dp1[i] + dp2[i] << " ";
    cout << "\n";
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
// https://codeforces.com/problemset/problem/2192/D