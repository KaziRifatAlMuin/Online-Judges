/*
    Author : RifatALmuiN
    Problem : Digits of Factorial
    Source : https://lightoj.com/problem/digits-of-factorial
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;

double logsum[1000007];

void pre_logsum_array()
{
    logsum[0] = 0;
    for(int i=1; i<1000007; i++){
        logsum[i] = log10(i) + logsum[i-1];
    }
}


void solve()
{
    int n, base, digit;
    cin>>n>>base;
    digit = logsum[n]/log10(base) + 1;
    cout<<digit<<endl;
}

int main()
{
    FAST_IO;
   #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
   #endif
    pre_logsum_array();
    int t = 1, case_number = 1;
    cin >> t;
    while(t--)
    {
        cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}

