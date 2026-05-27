#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector <ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    ll low = 0, high = n, ans = 0;
    while(low <= high){
        // TTTTTFFFFF
        ll mid = low + (high - low) / 2;
        bool ok = true;
        vector <bool> visited(mid, 0);
        vector <ll> trash;
        for(int i = 0; i < n; i++){
            if(v[i] < mid && !visited[v[i]]){
                visited[v[i]] = true;
            }
            else trash.push_back(v[i]);
        }
        sort(trash.begin(), trash.end());
        for(int i = 0, j = 0; i < mid && j < trash.size();){
            if(visited[i]){
                i++;
                continue;
            }
            ll best = (trash[j] & 1) ? trash[j]/2 : trash[j]/2 - 1;
            if(best >= i){
                visited[i] = true;
                i++;
            }
            j++;
        }
        for(int i = 0; i < mid; i++){
            if(!visited[i]) ok = false;
        }
        if(ok) low = mid + 1, ans = mid;
        else high = mid - 1;
    }
    cout << ans << "\n";
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
// https://codeforces.com/contest/2226/problem/C