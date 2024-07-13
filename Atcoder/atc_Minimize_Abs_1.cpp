#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 1e5 + 7;
int const mod = 998244353;

void solve()
{
    ll n, l, r;
    cin >> n >> l >> r;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++){
        int k;
        if(v[i] >= l && v[i] <= r) k = 0;
        else k = min(abs(v[i] - l), abs(v[i] - r));
        int x1 = v[i] + k, x2 = v[i] - k;
        if(x1 >= l && x1 <= r) cout << x1 << " ";
        else cout << x2 << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
// https://atcoder.jp/contests/abc330/tasks/abc330_b?lang=en