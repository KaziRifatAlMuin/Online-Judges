/*
    Author : RifatALmuiN
    Problem : Knights in Chessboard
    Source : https://lightoj.com/problem/knights-in-chessboard
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;


void solve()
{
    ll m, n;
    cin>>m>>n;
    ll box = m*n;
    if(m==1 || n==1) cout<<box<<endl;
    else if(box<=4) cout<<box<<endl;
    else if(m==2 || n==2){
        ll block = box/4;
        ll knt = (block+1)/2;
        cout<<(box%4 == 0? knt*4 : knt*4 + (block&1 ? 0 : 2))<<endl;
    }
    else{
        cout<<box/2 + box%2<<endl;
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
        cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}

