#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector<int>> G;
int n;
vector <int> depth;
vector <vector<int>> nodes;

void dfs(int u, int par = -1){
    if(par == -1) depth[u] = 0;
    else depth[u] = depth[par] + 1;
    nodes[depth[u]].push_back(u);
    for(auto v : G[u]){
        if(v == par) continue;
        dfs(v, u);
    }
}

void solve(){
    cin >> n;
    G.assign(n+1, {});
    nodes.assign(n+1, {});
    depth.assign(n+1, 0);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll max_depth = 0, max_node = 0, extra = 0;
    dfs(1);
    for(int d = 0; d <= n; d++){
        ll cnt = nodes[d].size();
        if(cnt >= max_node){
            max_node = cnt;
            max_depth = d;
        }
    }
    for(int i = 1; i <= n; i++){
        ll cnt = G[i].size();
        if(i != 1) cnt--;
        if(cnt == max_node){
            extra++;
            break;
        }
    }
    // cout << max_node << " " << extra << " : ";
    cout << max_node + extra << "\n";
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
// https://codeforces.com/problemset/problem/2183/D1