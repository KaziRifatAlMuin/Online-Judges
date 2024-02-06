/*
    Author : RifatALmuiN
    Problem : Higher Math
    Source : https://lightoj.com/problem/higher-math
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;

void solve()
{
    ll tri[3];
    cin>>tri[0]>>tri[1]>>tri[2];
    sort(tri,tri+3);
    cout<<(tri[0]*tri[0]+tri[1]*tri[1] == tri[2]*tri[2] ? "yes\n" : "no\n");
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

