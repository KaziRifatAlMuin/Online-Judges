/*
    Author : RifatALmuiN
    Problem : Circle in Square
    Source : https://lightoj.com/problem/circle-in-square
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;


void solve()
{
    double r, pi = acos(-1);
    cin>>r;
    printf("%.2lf\n",(4-pi)*r*r);
}

int main()
{
    //FAST_IO;
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

