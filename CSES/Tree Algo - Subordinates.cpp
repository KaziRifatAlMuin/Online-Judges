#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e5 + 7;

vector <int> G[N];
int dp[N];

int dfs(int v){
    for(auto sub : G[v]){
        dp[v] += (1 + dfs(sub));
    }
    return dp[v];
}

void solve()
{
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for(int i = 2; i <= n; i++){
        int u; cin >> u;
        G[u].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) cout << dp[i] << " ";
    cout << "\n";
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