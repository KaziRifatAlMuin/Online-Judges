#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> v(m);
    for(auto &i : v) cin >> i;
    int seg = n / k;
    int rem = n % k;
    int cnt = 0;
    for(auto x : v){
        if(x == seg + 1) cnt++;
        else if(x > seg + 1){
            YN(false);
            return;
        }
    }
    YN(cnt <= rem);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}