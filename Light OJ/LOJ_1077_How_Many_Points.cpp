#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    ll ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    ll dely = abs(ay - by), delx = abs(ax - bx);
    cout << __gcd(delx, dely) + 1 << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}