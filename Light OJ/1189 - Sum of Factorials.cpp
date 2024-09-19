/*
    Author : RifatALmuiN
    Problem : Sum of Factorials
    Source : https://lightoj.com/problem/sum-of-factorials
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

vll fact;

void preprocess()
{
    fact.pb(1); fact.pb(1);
    int i = 1;
    for(i = 2; i < 21; i++){
        fact.pb(fact[i-1]*i);
    }
}

void solve()
{
    ll n;
    cin >> n;
    vll ans;
    for(int i = 20; i >= 0; i--){
        if(fact[i] <= n){
            n -= fact[i];
            ans.pb(i);
        }
    }
    if(n==0){
        for(int i = ans.size()-1; i > 0; i--){
            cout << ans[i] << "!+";
        }
        cout << ans[0] << "!\n";
    }
    else{
        cout << "impossible\n";
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
    preprocess();
    cin >> t;
    while(t--)
    {
        cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}

