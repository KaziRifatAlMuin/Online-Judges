#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

void solve(){
    ll n;
    cin >> n;
    vector <ll> v(n);
    ll nimsum = 0, one = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        nimsum ^= v[i];
        one += (v[i] == 1);
    }
    if(one == n) one--;
    if(one & 1) cout << "Bob\n";
    else cout << "Alice\n";
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
// https://codeforces.com/problemset/problem/2181/F