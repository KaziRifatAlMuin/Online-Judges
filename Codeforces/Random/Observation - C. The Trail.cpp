#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll mat[n][m];
    vector <ll> row(n), col(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        ll sum = 0;
        for(int j = 0; j < m; j++){
            sum += mat[i][j];
        }
        row[i] = sum;
    }
    for(int j = 0; j < m; j++){
        ll sum = 0;
        for(int i = 0; i < n; i++){
            sum += mat[i][j];
        }
        col[j] = sum;
    }

    int r = 0, c = 0;
    for(auto x : s){
        if(x == 'R'){
            mat[r][c] = col[c] * -1;
            row[r] += mat[r][c];
            c++;
        }
        else{
            mat[r][c] = row[r] * -1;
            col[c] += mat[r][c];
            r++;
        }
    }
    if(s[s.size() - 1] == 'R') mat[n-1][m-1] = col[m-1] * -1;
    else mat[n-1][m-1] = row[n-1] * -1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    // for(int i = 0; i < n; i++){
    //     ll sum = 0;
    //     for(int j = 0; j < m; j++){
    //         sum += mat[i][j];
    //     }
    //     cout << sum << " ";
    // }
    // for(int j = 0; j < m; j++){
    //     ll sum = 0;
    //     for(int i = 0; i < n; i++){
    //         sum += mat[i][j];
    //     }
    //     cout << sum << " ";
    // }
    // cout << "\n";
    
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
// https://codeforces.com/contest/2055/problem/C