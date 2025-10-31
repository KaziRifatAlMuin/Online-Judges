#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector <string> s(n);
    ll cnt = 0, box = 0;
    for(int i = 0; i < n; i++) cin >> s[i];
    bool ok = false;
    set <ll> minus, plus;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == '#'){
                minus.insert(i-j);
                plus.insert(i+j);
                cnt++;
                if(i+1 < n && j+1 < n){
                    if(s[i][j+1] == '#' && s[i+1][j] == '#' && s[i+1][j+1] == '#') box = 1;
                }
            }
        }
    }

    ok |= (minus.size() <= 1 || plus.size() <= 1);
    ok |= (minus.size() == 2 && *(--minus.end()) - *minus.begin() == 1);
    ok |= (plus.size() == 2 && *(--plus.end()) - *plus.begin() == 1);
    ok |= (cnt == 4 && box == 1);

    if(ok) cout << "YES\n";
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
// https://codeforces.com/contest/2161/problem/B