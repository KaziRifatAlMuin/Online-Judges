#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 4e5 + 17;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s[n];
    int color[n][m];
    memset(color, 0, sizeof(color));
    bool f1 = false, f2 = false;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    bool ok = true;
    for(int i = 0; i < n && ok; i++){
        f1 = false;
        for(int j = 0; j < m && ok; j++){
            if(s[i][j] == 'U'){
                if(f1) color[i][j] = 1, f1 = false;
                else color[i][j] = -1, f1 = true;
            }
            else if(s[i][j] == 'D'){
                if(color[i-1][j] == 1) color[i][j] = -1;
                else color[i][j] = 1; 
            }
        }
    }
    for(int j = 0; j < m && ok; j++){
        f2 = false;
        for(int i = 0; i < n && ok; i++){
            if(s[i][j] == 'L'){
                if(f2) color[i][j] = 1, f2 = false;
                else color[i][j] = -1, f2 = true;
            }
            else if(s[i][j] == 'R'){
                if(color[i][j-1] == 1) color[i][j] = -1;
                else color[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        ll sum = 0;
        for(int j = 0; j < m; j++){
            sum += color[i][j];
        }
        if(sum != 0) ok = false;
    }
    for(int j = 0; j < m; j++){
        ll sum = 0;
        for(int i = 0; i < n; i++){
            sum += color[i][j];
        }
        if(sum != 0) ok = false;
    }
    if(!ok) cout << -1 << "\n";
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(color[i][j] == 0) cout << '.';
                else if(color[i][j] == -1) cout << 'W';
                else if(color[i][j] == 1) cout << 'B';
            }
            cout << "\n";
        }
    }
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
// https://codeforces.com/problemset/problem/1863/D