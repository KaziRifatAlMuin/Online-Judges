#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

void solve(){
    ll n;
    cin >> n;
    vector <ll> v(n), dist(n+1, -1);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    queue <ll> q;
    for(auto x : v){
        if(x <= n) dist[x] = 1, q.push(x);
    }
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(auto x : v){
            if(cur * x > n) break;
            ll xx = cur * x;
            if(dist[xx] == -1){
                dist[xx] = dist[cur] + 1;
                q.push(xx);
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << dist[i] << (i == n ? "\n" : " ");
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
// https://codeforces.com/problemset/problem/2193/E