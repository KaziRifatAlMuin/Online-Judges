#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector<int>> G;
vector <int> sub, dp;
int n, k;

void dfs(int u, int par = -1){
    sub[u] = 1;
    for(auto v : G[u]){
        if(v == par) continue;
        dfs(v, u);
        sub[u] += sub[v];
    }
}

// parent subtree = n

void dfs2(int u, int par = -1){
    for(auto v : G[u]){
        if(v == par) continue;
        int diff = 0, x = sub[v];
        if(x < k) diff++; // x -> n
        if(n - x < k) diff--; // n -> n-x
        dp[v] = dp[u] + diff;
        dfs2(v, u);
    }
}


void solve(){
    cin >> n >> k;
    G.assign(n+1, {});
    sub.assign(n+1, 0);
    dp.assign(n+1, 0);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int cuteness = 0;
    dfs(1);
    for(int i = 1; i <= n; i++){
        if(sub[i] >= k) cuteness++;
    }
    dp[1] = cuteness;
    dfs2(1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        // cout << dp[i] << " ";
        ans += dp[i];
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
    return 0;
}
// https://codeforces.com/contest/2167/problem/F