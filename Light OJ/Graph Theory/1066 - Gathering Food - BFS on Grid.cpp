#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

ll n, m;
vector<vector<ll>> level;
vector<vector<bool>> visited;
vector<vector<char>> s;

ll bfs(ll sr, ll sc, ll er, ll ec, char c1, char c2){
    queue<pair<ll,ll>> Q;
    Q.push({sr, sc});
    level.assign(n+1, vector<ll> (m+1, inf));
    visited.assign(n+1, vector<bool> (m+1, 0));
    visited[sr][sc] = true;
    level[sr][sc] = 0;
    while(!Q.empty()){
        auto node = Q.front(); Q.pop();
        for(ll i = 0; i < 4; i++){
            ll r = node.first + dr[i];
            ll c = node.second + dc[i];
            if(r >= 0 && r < n && c >= 0 && c < m && !visited[r][c] && (s[r][c] == '.' || (s[r][c] >= 'A' && s[r][c] <= c2))) {
                Q.push({r,c});
                visited[r][c] = true;
                level[r][c] = level[node.first][node.second] + 1;
            }
        }
    }
    return level[er][ec];
}

void solve(){
    cin >> n;
    m = n;
    s.assign(n, vector<char>(m,' '));

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> s[i][j];
        }
    }

    vector <tuple<char,ll,ll>> check;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(s[i][j] >= 'A' && s[i][j] <= 'Z') check.push_back({s[i][j], i, j});
        }
    }
    sort(check.begin(), check.end());
    ll ans = 0;
    bool ok = true;

    for(ll i = 1; i < check.size() && ok; i++){
        auto [c1, sr, sc] = check[i-1];
        auto [c2, er, ec] = check[i];
        ll dis = 0;
        dis = bfs(sr, sc, er, ec, c1, c2);
        if(dis == inf) ok = false;
        else ans += dis; 
    }
    if(!ok) cout << "Impossible\n";
    else cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock(), cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}