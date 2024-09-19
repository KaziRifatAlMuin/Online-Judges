#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 10056;
int const N = 1007;

void solve()
{
    double v1, v2, v3, a1, a2, t1, t2, t3;
    cin >> v1 >> v2 >> v3 >> a1 >> a2;
    t1 = v1 / a1, t2 = v2 / a2;
    t3 = max(t1, t2);
    double d = (v1 * t1 + v2 * t2) / 2;
    double s = v3 * t3;
    cout << fixed << setprecision(10) << d << " " << s << "\n";
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