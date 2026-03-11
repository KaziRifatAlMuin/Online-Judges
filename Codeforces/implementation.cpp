#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector <ll> v(n), last(n+1), alive(n+1), ans;
    vector <queue<ll>> inds(n+1);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        inds[v[i]].push(i);
        last[v[i]] = i;
        alive[v[i]] = 1;
    }
    set <ll> st_last;
    multiset <ll> opts;
    for(int val = 1; val <= n; val++){
        if(alive[val]) st_last.insert(last[val]);
    }

    auto kill = [&] (ll val){
        alive[val] = 0;
        st_last.erase(last[val]);
        opts.erase(val);
    };

    auto add = [&] (ll idx){
        ll x = v[idx];
        if(!alive[x]) return;
        opts.insert(x);
    };

    auto erase = [&] (ll idx){
        ll x = v[idx];
        inds[x].pop();
        if(alive[x]) opts.erase(opts.find(x));
    };

    ll l = 0, r = 0;
    while(st_last.size()){
        ll R = *st_last.begin();
        while(r <= R) add(r++);
        ll cur = (ans.size() & 1) ? *opts.begin() : *opts.rbegin();
        ans.push_back(cur);
        kill(cur);
        ll L = inds[cur].front();
        while(l <= L) erase(l++);
    }

    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
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
// https://codeforces.com/problemset/problem/2001/D