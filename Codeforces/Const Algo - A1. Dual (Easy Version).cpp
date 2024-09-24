#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e7 + 7;

void solve()
{
    ll n;
    cin >> n;
    vector <ll> v(n);
    vector <pair<ll,ll>> ans;
    ll pos = -100, neg = 100, pk, nk;
    for(ll i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] > pos){
            pos = v[i];
            pk = i + 1;
        }
        if(v[i] < neg){
            neg = v[i];
            nk = i + 1;
        }
    }
    if(neg >= 0 || (pos >= 0 && abs(pos) >= abs(neg))){
        ans.push_back({pk, pk});
        ans.push_back({pk, pk});
        ans.push_back({1, pk});
        ans.push_back({1, 1});
        ans.push_back({1, 1});
        for(ll i = 2; i <= n; i++){
           ans.push_back({i, i-1});
           ans.push_back({i, i}); 
        }
    }
    else{
        ans.push_back({nk, nk});
        ans.push_back({nk, nk});
        ans.push_back({n, nk});
        ans.push_back({n, n});
        ans.push_back({n, n});
        for(ll i = n - 1; i >= 1; i--){
           ans.push_back({i, i+1});
           ans.push_back({i, i}); 
        }
    }
    cout << ans.size() << "\n";
    for(auto x : ans){
        cout << x.first << " " << x.second << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1854/problem/A1