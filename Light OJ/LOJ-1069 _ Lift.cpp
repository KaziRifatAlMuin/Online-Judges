/*
    Author : RifatALmuiN
    Problem : Lift
    Source : https://lightoj.com/problem/lift
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;


void solve()
{
    int p, lift;
    cin>>p>>lift;
    cout<< (p<=lift ? lift*4 + 19 : (2*p-lift)*4 + 19)<<endl;
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

