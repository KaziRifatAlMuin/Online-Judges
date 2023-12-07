#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
long long int const MOD = 1e9 + 7;


void solve() 
{
    int n, m; cin >> n >> m;
    int a[n + 1], b[m + 1];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int all = 0;
    for (int i = 1; i <= m; i++) {
      cin >> b[i];
      all |= b[i];
    }
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
      x ^= a[i];
      y ^= a[i] | all;
    }
    cout << min(x, y) << ' ' << max(x, y) << '\n';
}

int main()
{
    FAST_IO

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1, case_number = 1;
    cin >> t;
    while(t--)
    {
        //cout << "Case " << case_number++ << ":\n";
        solve();
    }
    return 0;
}

/*


Coded by RifatALmuiN

Input
_______________________________

_______________________________


Output
_______________________________

_______________________________


*/
    