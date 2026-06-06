#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector<int>> G;
vector <int> color;

bool dfs(int u, int c, int& ct0, int& ct1){
    color[u] = c;
    if(c) ct1++;
    else ct0++;

    bool bipartite = true;
    for(auto v : G[u]){
        if(color[v] == -1){
            if(!dfs(v, !c, ct0, ct1)) bipartite = false;
        }
        else if(color[v] == color[u]) bipartite = false;
    }
    return bipartite;
}

void solve(){
    int n, m;
    cin >> n >> m;
    G.assign(n+1, {});
    color.assign(n+1, -1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(color[i] != -1) continue;
        int ct0 = 0, ct1 = 0;
        if(dfs(i, 0, ct0, ct1)) ans += max(ct0, ct1);
    }
    cout << ans << "\n";
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