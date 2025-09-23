#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector <ll> v(n), neg, pos, ans;
    ll maxi = -1e9, mini = 1e9;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        maxi = max(v[i], maxi);
        mini = min(v[i], mini);
        if(v[i] < 0) neg.push_back(v[i]);
        else pos.push_back(v[i]);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    ll range = maxi - mini;
    bool ok = true;
    ll cur = 0;
    while(neg.size() > 0 || pos.size() > 0){
        if(pos.size() > 0 && neg.size() == 0){
            cur += pos.back();
            ans.push_back(pos.back());
            pos.pop_back();
        }
        else if(neg.size() > 0 && pos.size() == 0){
            cur += neg.back();
            ans.push_back(neg.back());
            neg.pop_back();
        }
        else{
            ll a = cur + pos.back();
            ll b = cur + neg.back();
            if(abs(a) < abs(b)){
                cur += pos.back();
                ans.push_back(pos.back());
                pos.pop_back();
            }
            else{
                cur += neg.back();
                ans.push_back(neg.back());
                neg.pop_back();
            }
        }
        if(abs(cur) >= range) ok = false;
    }
    if(ok){
        cout << "Yes\n";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
    else cout << "No\n";

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
// https://codeforces.com/problemset/problem/1798/D