#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> G[n+1], nodes[n+1], color(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        cin >> color[i];
        nodes[color[i]].push_back(i);
    }
    bool ok = true;
    vector <int> ans;
    for(int col = 1; col <= n && ok; col++){
        for(auto u : nodes[col]){
            ans.push_back(u);
            set <int> st;
            for(auto v: G[u]){
                if(color[v] < color[u]) st.insert(color[v]);
                if(color[v] == color[u]) ok = false;
            }
            if(st.size() != color[u] - 1){
                ok = false;
                break;
            }
        }
    }
    if(!ok) cout << -1 << "\n";
    else{
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
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
// https://codeforces.com/contest/1362/problem/D