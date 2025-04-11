#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dr[4] = {1, -1, 0, 0}; // D, U, R, L
int dc[4] = {0, 0, 1, -1}; // D, U, R, L

int n, m;
vector<vector<int>> level;
vector<vector<bool>> visited;
vector<vector<char>> s;
vector<vector<pair<pair<int,int>,char>>> parent;
string turn = "DURL";

void bfs(int sr, int sc, int er, int ec){
    queue<pair<int,int>> Q;
    Q.push({sr, sc});
    visited[sr][sc] = true;
    while(!Q.empty()){
        auto node = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int r = node.first + dr[i];
            int c = node.second + dc[i];
            if(r >= 0 && r < n && c >= 0 && c < m && !visited[r][c] && (s[r][c] == '.' || s[r][c] == 'B')) {
                Q.push({r,c});
                visited[r][c] = true;
                level[r][c] = level[node.first][node.second] + 1;
                parent[r][c] = {{node.first, node.second}, turn[i]};
            }
        }
    }
}

void solve(){
    int sr, sc, er, ec;
    cin >> n >> m;
    s.assign(n, vector<char>(m,' '));
    visited.assign(n, vector<bool>(m,false));
    level.assign(n, vector<int>(m,0));
    parent.assign(n, vector<pair<pair<int,int>,char>>(m, {{0,0},' '}));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> s[i][j];
            if(s[i][j] == 'A') sr = i, sc = j;
            else if(s[i][j] == 'B') er = i, ec = j;
        }
    }

    bfs(sr, sc, er, ec);

    if(!visited[er][ec]){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    string ans;
    int r = er, c = ec;
    while(r != sr || c != sc){
        auto p = parent[r][c];
        ans += p.second;
        r = p.first.first;
        c = p.first.second;
    }
    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
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
// https://cses.fi/problemset/task/1193