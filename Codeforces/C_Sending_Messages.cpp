#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    ll n, f, a, b;
    cin >> n >> f >> a >> b;
    vector <ll> m(n);
    for(auto &x : m) cin >> x;
    ll prev = 0, ans = 0;
    for(auto x : m){
        ans += min((x - prev) * a, b);
        prev = x;
    }
    YN(ans < f);
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