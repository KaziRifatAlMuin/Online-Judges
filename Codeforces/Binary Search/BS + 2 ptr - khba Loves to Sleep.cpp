#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k, x;
    cin >> n >> k >> x;
    vector <ll> v(n), ans(k);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll low = 0, high = x, maxi = 0;
    while(low <= high){ // TTTTFFFF
        ll mid = low + (high - low) / 2;
        vector <ll> temp;
        ll cur = 0, lim = v[0];
        if(mid != 0){
            while(cur + mid <= v[0] && temp.size() < k){
                temp.push_back(cur);
                cur++;
            }
            cur = x;
            while(cur - mid >= v[n-1] && temp.size() < k){
                temp.push_back(cur);
                cur--;
            }
            ll cur = v[0] + mid;
            for(int i = 0; i+1 < n && temp.size() < k; ){
                if(cur - mid >= v[i] && cur + mid <= v[i+1]){
                    temp.push_back(cur);
                    cur++;
                }
                else{
                    i++;
                    cur = v[i] + mid;
                }
            }
        }
        else{
            for(int j = 0; j < k; j++) temp.push_back(j);
        }

        if(temp.size() == k){
            ans = temp;
            low = mid + 1;
            maxi = mid;
        }
        else high = mid - 1;
    }
    sort(ans.begin(), ans.end());
    for(auto it : ans) cout << it << " ";
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
// https://codeforces.com/contest/2167/problem/E