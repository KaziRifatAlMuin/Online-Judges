/*
    Author : RifatALmuiN
    Problem : How Cow
    Source : https://lightoj.com/problem/how-cow
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;


void solve()
{
    int x1,x2,y1,y2,x,y,n;
    cin>>x1>>y1>>x2>>y2>>n;
    while(n--){
        cin>>x>>y;
        cout<<(x>x1 && x<x2 && y>y1 && y<y2 ? "Yes\n" : "No\n");
    }
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
        cout << "Case " << case_number++ << ":\n";
        solve();
    }
    return 0;
}

