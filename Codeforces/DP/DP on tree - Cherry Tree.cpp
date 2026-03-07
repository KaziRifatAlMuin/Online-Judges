#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

vector <vector<int>> G;
vector <vector<bool>> dp;

void dfs(int u, int par = -1){
    dp[u] = {0, 1, 0}; // base case or shake it
    if(G[u].size() == 1 && par != -1) return;
    vector <int> dp_child = {1, 0, 0}; // shake 0
    for(auto v : G[u]){
        if(v == par) continue;
        dfs(v, u);
        vector <int> dp_child_new(3,0);
        for(int i = 0; i < 3; i++){
            if(dp[v][i] == 0) continue;
            for(int j = 0; j < 3; j++){
                dp_child_new[(i+j)%3] |= dp_child[j];
            }
        }
        dp_child = dp_child_new;
    }
    dp[u][0] = dp_child[0];
    dp[u][2] = dp_child[2];
}

void solve(){
    int n;
    cin >> n;
    G.assign(n+1, {});
    dp.assign(n+1, vector<bool>(3, 0));
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    if(dp[1][0]) cout << "YES\n";
    else cout << "NO\n";
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
// https://codeforces.com/contest/2184/problem/F