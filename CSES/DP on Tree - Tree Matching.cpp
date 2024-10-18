#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e5 + 7;

vector <int> G[N];

pair <int,int> dfs(int u, int par = -1){
    if(u == par) return {0,0};
    int zerotake = 0, onetake = 0;
    vector <int> subZeroTake, subOneTake;
    for(auto v: G[u]){
        if(v == par) continue;
        pair <int, int> sub = dfs(v, u);
        zerotake += max(sub.first, sub.second);
        subZeroTake.push_back(sub.first);
        subOneTake.push_back(sub.second);
        // cout << v << " " << u << "\n";
    }
    for(int i = 0; i < subZeroTake.size(); i++){
        onetake = max(onetake, 1 + zerotake - max(subZeroTake[i], subOneTake[i]) + subZeroTake[i]);
    }
    // cout << u << " " << par << " " << zerotake << " " << onetake << "\n";
    return {zerotake, onetake};
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int u, v; 
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    pair <int, int> ans = dfs(1);
    cout << max(ans.first, ans.second) << "\n";
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
// https://cses.fi/problemset/task/1130/