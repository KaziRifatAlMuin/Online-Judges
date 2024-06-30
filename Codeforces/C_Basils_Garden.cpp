#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    vector <ll> v(n);
    ll ans = 0;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++){
        ans = max(ans, v[i] + i);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
// https://codeforces.com/contest/1987/problem/C