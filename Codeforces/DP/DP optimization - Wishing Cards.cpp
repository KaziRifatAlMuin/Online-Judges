#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<bool> marked(n, false);
    set<ll> s;

    for(int i = 0; i < n; i++) {
        if(s.count(a[i]) == 0) {
            marked[i] = true;
            s.insert(a[i]);
        }
    }

    vector<pair<ll,ll>> v;
    for(int i = 0; i < n; i++) {
        if(marked[i]) v.push_back({i, a[i]});
    }

    if(v.size() == 1) {
        cout << min(a[0], k) * n << '\n';
        return;
    }

    int m = v.size();

    vector<vector<ll>> dp_prev(k+1, vector<ll>(k+1, LLONG_MIN));
    vector<vector<ll>> dp_cur(k+1, vector<ll>(k+1, LLONG_MIN));
    vector<vector<ll>> pre_prev(k+1, vector<ll>(k+1, LLONG_MIN));
    vector<vector<ll>> pre_cur(k+1, vector<ll>(k+1, LLONG_MIN));

    // base case
    for(int i = 0; i <= v[0].second && i <= k; i++) {
        dp_prev[i][i] = i * (v[1].first - v[0].first);
    }

    for(int j = 0; j <= k; j++) {
        pre_prev[0][j] = dp_prev[0][j];
        for(int l = 1; l <= k; l++) {
            pre_prev[l][j] = max(pre_prev[l-1][j], dp_prev[l][j]);
        }
    }

    for(int i = 1; i < m; i++) {

        for(int x = 0; x <= k; x++)
            for(int y = 0; y <= k; y++)
                dp_cur[x][y] = dp_prev[x][y];

        ll nex = (i == m - 1) ? (n - v[i].first)
                             : (v[i+1].first - v[i].first);

        for(int prev = 0; prev <= k; prev++) {

            // take new max
            for(int j = 0; j <= v[i].second && j + prev <= k; j++) {
                if(pre_prev[j][prev] == LLONG_MIN) continue;

                dp_cur[j][j + prev] = max(
                    dp_cur[j][j + prev],
                    pre_prev[j][prev] + nex * j
                );
            }

            // continue old max
            for(int last = 0; last <= k; last++) {
                if(dp_prev[last][prev] == LLONG_MIN) continue;

                dp_cur[last][prev] = max(
                    dp_cur[last][prev],
                    dp_prev[last][prev] + nex * last
                );
            }
        }

        // build prefix
        for(int j = 0; j <= k; j++) {
            pre_cur[0][j] = dp_cur[0][j];
            for(int l = 1; l <= k; l++) {
                pre_cur[l][j] = max(pre_cur[l-1][j], dp_cur[l][j]);
            }
        }

        // swap
        dp_prev = dp_cur;
        pre_prev = pre_cur;
    }

    ll ans = 0;
    for(int i = 0; i <= k; i++) {
        ans = max(ans, pre_prev[k][i]);
    }

    cout << ans << '\n';
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
// https://codeforces.com/contest/2174/problem/B