/*
    Author : RifatALmuiN
    Problem : Division by 3
    Source : https://lightoj.com/problem/division-by-3
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
typedef vector <int> vi;
typedef vector <long long int> vl;
typedef pair <int, int> pii;
typedef pair <long long int, long long int> pll;

bool not_div(ll n)
{
    --n;
    if(n % 3 == 0) return true;
    return false;
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    ll num = b - a + 1;
    ll k = num/3;
    if(not_div(a)){
        if(not_div(b) || not_div(b-1))
            k++;
    }
    else if(not_div(a+1)){
        if(not_div(b))
            k++;
    }
    cout << num - k << endl;

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

