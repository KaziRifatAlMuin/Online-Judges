#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m;
    cin >> n >> m;
    ll cnt = 0;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j]) cnt++;
        }
    }
    ll endi = 0, endj = 0, cur = 0, target = cnt / 2, found = 0;
    for(int j = 0; j < m && !found; j++){
        for(int i = n-1; i >= 0 && !found; i--){
            if(a[i][j]){
                cur++;
                if(cur == target){
                    endi = i;
                    endj = j;
                    found = 1;
                }
            }
        }
    }
    cout << target * (cnt - target) << "\n";
    for(int j = 0; j < endj; j++) cout << "R";
    for(int i = 0; i < endi; i++) cout << "D";
    cout << "R";
    for(int i = endi; i < n; i++) cout << "D";
    for(int j = endj+1; j < m; j++) cout << "R";
    cout << "\n";
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
// https://codeforces.com/contest/2194/problem/D