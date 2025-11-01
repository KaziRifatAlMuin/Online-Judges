#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector<ll>> dp;
vector <ll> v, p;
ll n;

ll run(int i, int prev){
    if(i == n) return 0;
    if(dp[i][prev+1] != -1) return dp[i][prev+1];
    ll ans = run(i+1, prev); // not take
    if(prev == -1 || v[prev] <= v[i]){
        ans = max(ans, p[i] + run(i+1, i));
    }
    return dp[i][prev+1] = ans; // +1 for cordinate shift
}

void solve(){
    cin >> n;
    v.assign(n, 0);
    p.assign(n, 0);
    // dp.assign(n+1, vector<ll>(n+1, -1));
    for(int i = 0; i < n; i++) cin >> v[i];
    ll sum = 0, ans = 0;
    for(int i = 0; i < n; i++) cin >> p[i], sum += p[i];

    vector <ll> next(n+1, 0), cur(n+1, 0);
    for(int i = n-1; i >= 0; i--){
        for(int prev = i-1; prev >= -1; prev--){
            ans = next[prev+1]; // not take
            if(prev == -1 || v[prev] <= v[i]){ // take
                ans = max(ans, p[i] + next[i+1]); // +1 for shift
            }
            cur[prev+1] = ans;
        }
        next = cur;
    }
    cout << sum - ans << "\n";
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
// https://codeforces.com/contest/2167/problem/G