/*
    Author : RifatALmuiN
    Problem : Brush (I)
    Source : https://lightoj.com/problem/brush-1
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;


void solve()
{
    int n, a, sum=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        if(a>0) sum += a;
    }
    cout<<sum<<endl;
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

