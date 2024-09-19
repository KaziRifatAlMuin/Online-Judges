#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const mod = 998244353;
int const N = 2e5 + 5;

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll need = (((k + 1) * (k + 2)) / 2) - 2;
    // cout << need << " ";
    if(n >= need) cout << "YES\n";
    else cout << "NO\n";
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
