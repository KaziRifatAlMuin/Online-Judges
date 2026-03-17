#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

void solve(){
    ll n, m;
    cin >> n >> m;
    vector <pair<ll,ll>> v, ans;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    ll kill = n - m;
    if(kill < (n+1) / 2){
        cout << -1 << "\n";
        return;
    }
    if(m == 0){
        ll sum = 0, pos = -1;
        for(int i = n-2; i >= 0; i--){
            sum += v[i].first;
            if(sum >= v[n-1].first){
                pos = i;
                break;
            }
        }
        if(pos == -1){
            cout << -1 << "\n";
            return;
        }
        for(int i = 0; i < pos; i++){
            ans.push_back({v[i].second, v[i+1].second});
        }
        for(int i = pos; i < n-1; i++){
            ans.push_back({v[i].second, v[n-1].second});
        }
    }
    else{
        for(int i = 0; i < n; i++){
            if(i + (n-i)/2 == kill){
                for(int j = 1; j <= i; j++){
                    ans.push_back({v[j-1].second, v[j].second});
                }
                for(int j = n-1; j > i; j -= 2){
                    ans.push_back({v[j].second, v[j-1].second});
                }
                break;
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto[x, y] : ans){
        cout << x+1 << " " << y+1 << "\n";
    }
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
// https://codeforces.com/contest/2178/problem/D