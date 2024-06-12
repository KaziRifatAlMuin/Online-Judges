#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const mod = 998244353;
int const N = 2e5 + 5;
#define PI acos(-1.0)

void solve()
{
    ll a;
    cin >> a;
    if(a == 2) cout << a * 2ll << " " << a * a * a << "\n";
    else cout << a * 2ll << " " << a * a << "\n";
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
