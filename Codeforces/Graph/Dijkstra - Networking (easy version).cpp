#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

vector <vector<pair<ll,ll>>> G;

struct info{
    ll v, w;
    bool const operator < (const info node) const{
        return w > node.w;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    G.assign(n+1, {});
    for(int i = 0; i < m+n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    for(int i = 1; i <= k; i++){
        vector <ll> dist(n+1, 1e17);
        dist[i] = 0;
        priority_queue <info> q;
        q.push({i, 0});
        while(!q.empty()){
            info cur = q.top();
            q.pop();
            if(cur.w > dist[cur.v]) continue;
            for(auto x : G[cur.v]){
                ll v = x.first;
                ll w = x.second;
                if(dist[v] > cur.w + w){
                    dist[v] = cur.w + w;
                    q.push({v, dist[v]});
                }
            }
        }
        for(int j = 1; j <= k; j++) cout << dist[j] << " ";
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
// https://codeforces.com/gym/106195/problem/D1