/*
    Author : RifatALmuiN
    Problem : Parity
    Source : https://lightoj.com/problem/parity
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
typedef vector <int> vi;
typedef vector <long long int> vll;
typedef pair <int, int> pii;
typedef pair <long long int, long long int> pll;
#define pb push_back
#define all(v) v.begin(), v.end()

void solve()
{
    int n, one = 0;
    cin >> n;
    while(n){
        if(n & 1) one++;
        n /= 2;
    }
    cout << (one & 1 ? "odd\n" : "even\n"); 
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

