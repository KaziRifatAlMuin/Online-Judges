/*
    Author : RifatALmuiN
    Problem : ICPC Standing
    Source : https://lightoj.com/problem/icpc-standing
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;


void solve()
{
    ll p, s, r;
    cin>>p>>s>>r;
    cout<< (p==s && r!=1 ? "No\n" : "Yes\n");
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
    while(t--)
    {
        cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}

