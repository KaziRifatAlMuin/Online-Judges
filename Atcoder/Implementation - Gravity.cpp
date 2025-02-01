#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, w;
    cin >> n >> w;
    vector <int> block[w];
    vector <pair<int,int>> v;
    vector <int> rank(n+1);
    map <pair<int,int>, int> pos;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        v.push_back({x, y});
        pos[{x,y}] = i + 1;
        block[x].push_back(y);
    }
    
    int mini = n;
    for(int i = 0; i < w; i++){
        sort(block[i].begin(), block[i].end());
        int sz = block[i].size();
        // cout << sz << " ";
        mini = min(mini, sz);
    }
    vector <int> life(mini + 1, 0);
    for(int i = 0; i < w; i++){
        int r = 1;
        for(auto j : block[i]){
            rank[pos[{i, j}]] = r;
            if(r <= mini) life[r] = max(life[r], j+1);
            r++;
        }
    }
    // for(int i = 1; i <= mini; i++){
    //     cout << i << " : " << life[i] << "\n";
    // }
    

    int q;
    cin >> q;
    while(q--){
        int t, a;
        cin >> t >> a;
        if(mini == 0){
            cout << "Yes\n";
        }
        else{
            auto [x, y] = v[a-1];
            if(rank[a] > mini) cout << "Yes\n";
            else{
                // cout << t << " " << life[rank[a]] << "\n";
                if(t < life[rank[a]]) cout << "Yes\n";
                else cout << "No\n";
            }
        }
    }
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
// https://atcoder.jp/contests/abc391/tasks/abc391_d