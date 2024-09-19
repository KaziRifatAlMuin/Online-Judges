/*
    Author : RifatALmuiN
    Problem : Redirect URL
    Source : https://lightoj.com/problem/redirect-url
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;


void solve()
{
    string str;
    cin>>str;
    if(str[4]!='s') str.insert(4,"s");
    cout<<str<<endl;
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

