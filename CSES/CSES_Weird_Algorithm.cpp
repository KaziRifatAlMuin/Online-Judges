#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e5 + 11;
const long long int INF = LLONG_MAX;

void solve()
{
    ll n;
    cin >> n;
    cout << n << " ";
    while(n != 1){
        n = n & 1 ? 3 * n + 1 : n / 2;
        cout << n << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1, case_number = 1;
    // cin >> t;

    while(t--)
    {
        // cout << "Case " << case_number++ << ": ";
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
