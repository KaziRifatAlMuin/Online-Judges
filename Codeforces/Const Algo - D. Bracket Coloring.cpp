#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 4e5 + 17;

void solve()
{
    int n, p = 0, sum = 0;
    string s;
    cin >> n >> s;
    vector <int> pre(n), ans(n);
    bool ok = true;
    for(int i = 0, seg = 1; i < n && ok; i++){
        if(s[i] == '(') p++;
        else p--;
        pre[i] = p;
        if(pre[i] > 0) ans[i] = 1;
        else if(pre[i] < 0) ans[i] = -1;
        if(i > 0 && (ans[i] == ans[i-1] || pre[i] == 0)) seg++;
        else seg = 1;
        // cout << ans[i] << " -> ";
        if(pre[i] == 0 && seg % 2 == 0) ans[i] = ans[i-1];
        else if(pre[i] == 0) ok = false;
        sum += ans[i];
    }

    if(!ok || pre[n-1] != 0) cout << -1 << "\n";
    else if(abs(sum) == n){
        cout << 1 << "\n";
        for(int i = 0; i < n; i++) cout << 1 << " ";
        cout << "\n";
    }
    else{
        cout << 2 << "\n";
        for(int i = 0; i < n; i++) cout << (ans[i] == 1 ? 1 : 2) << " ";
        cout << "\n";
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
// https://codeforces.com/problemset/problem/1837/D