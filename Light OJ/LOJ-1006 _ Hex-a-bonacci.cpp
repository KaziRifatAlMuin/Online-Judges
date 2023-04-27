/*
    Author : RifatALmuiN
    Problem : Hex-a-bonacci
    Source : https://lightoj.com/problem/hex-a-bonacci
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;

#define MOD 10000007

void solve()
{
    ll a, b, c, d, e, f, n, dp[10001];
    cin>>a>>b>>c>>d>>e>>f>>n;
    dp[0] = a % MOD;
    dp[1] = b % MOD;
    dp[2] = c % MOD;
    dp[3] = d % MOD;
    dp[4] = e % MOD;
    dp[5] = f % MOD;
    for (int i = 6; i <= n; i++) {
        dp[i] = (dp[i-1] % MOD + dp[i-2] % MOD + dp[i-3] % MOD + dp[i-4] % MOD + dp[i-5] % MOD + dp[i-6] % MOD) % MOD;
    }
    cout<<dp[n]<<endl;
}

int main()
{
    FAST_IO;
   #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
   #endif
    int t = 1, case_number = 1;
    cin >> t;
    getchar();
    while(t--)
    {
        cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}

