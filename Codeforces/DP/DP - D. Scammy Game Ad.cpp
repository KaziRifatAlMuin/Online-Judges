#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector <ll> l(n), r(n);
    vector <char> opl(n), opr(n);
    for(int i = 0; i < n; i++){
        cin >> opl[i] >> l[i] >> opr[i] >> r[i];
    }
    ll f1, f2, b1, b2, a, b, c;
    a = b = 1; c = 0;
    for(int i = n - 1; i >= 0; i--){
        f1 = f2 = b1 = b2 = 0;
        if(opl[i] == 'x') f1 = l[i] - 1;
        else b1 = l[i];
        if(opr[i] == 'x') f2 = r[i] - 1;
        else b2 = r[i];
        ll aa, bb, cc;
        if(a >= b){
            aa = a * (1 + f1);
            bb = b + a * f2;
            cc = a * (b1 + b2) + c;
        }
        else{
            aa = a + b * f1;
            bb = b * (1 + f2);
            cc = b * (b1 + b2) + c;
        }
        a = aa, b = bb, c = cc;
    }
    ll sum = a + b + c;
    cout << sum << "\n";
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
// https://codeforces.com/contest/2078/problem/D