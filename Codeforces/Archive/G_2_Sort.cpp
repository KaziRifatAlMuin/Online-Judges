#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result) ? cout << "YES\n" : cout << "NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    int ok[n];
    for (int i = 0; i < n - 1; i++)
        ok[i] = (a[i] < 2 * a[i + 1]);
    int tot = 0;
    for (int i = 0; i < k; i++)
        tot += ok[i];
    int res = 0;
    if (tot == k)
        res++;
    for (int i = k; i < n - 1; i++)
    {
        tot += ok[i];
        tot -= ok[i - k];
        if (tot == k)
            res++;
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}