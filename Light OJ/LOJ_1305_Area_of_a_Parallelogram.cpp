#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    ll ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    ll dx = ax + cx - bx; // (ax + cx)/2 = mx = (bx + dx)/2
    ll dy = ay + cy - by; // (ay + cy)/2 = my = (by + dy)/2
    ll area = abs(((ax * by) + (bx * cy) + (cx * dy) + (dx * ay)) - ((ay * bx)  + (by * cx)  + (cy * dx)  + (dy * ax))) / 2.0;
    cout << dx << " " << dy << " " << area << "\n"; // works only for integer
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