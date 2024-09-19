#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    double ox, oy, ax, ay, bx, by;
    cin >> ox >> oy >> ax >> ay >> bx >> by;
    double OA = sqrt((ax-ox)*(ax-ox) + (ay-oy)*(ay-oy));
    double AB = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
    double OB = sqrt((bx-ox)*(bx-ox) + (by-oy)*(by-oy));
    double AOB = acos((OA * OA + OB * OB - AB * AB)/(2 * OA * OB));
    cout << fixed << setprecision(10) << OA * AOB << "\n";
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