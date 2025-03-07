#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll m, n;
    cin >> m >> n;
    vector <ll> t(n), z(n), y(n), done(n);
    for(int i = 0; i < n; i++) cin >> t[i] >> z[i] >> y[i];
    ll low = 0, high = 1e9, ans = 0;
    while(low <= high){ // FFFFFTTTTT
        ll mid = low + (high - low) / 2;
        bool ok = false;
        ll cnt = 0;
        vector <ll> temp;
        for(int i = 0; i < n; i++){
            ll lo = 0, hi = 1e9, b = 0, time = mid;
            while(lo <= hi){ // TTTTFFFF
                ll midCnt = lo + (hi - lo) / 2;
                bool can = false;
                ll batchtime = (t[i] * z[i]) + y[i];
                ll batch = midCnt / z[i];
                ll taken = batch * batchtime + (midCnt % z[i]) * t[i];
                if(midCnt % z[i] == 0) taken -= y[i];
                if(taken <= time) can = true;
                if(can) b = midCnt, lo = midCnt + 1;
                else hi = midCnt - 1;
            }
            temp.push_back(b);
            cnt += b;
        }
        if(cnt >= m) ok = true; 
        if(ok){
            ans = mid;
            done = temp;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << ans << "\n";
    ll total = 0;
    for(auto x : done){
        if(total + x <= m) cout << x << " ";
        else if(total >= m) cout << 0 << " ";
        else cout << m - total << " ";
        total += x;
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D