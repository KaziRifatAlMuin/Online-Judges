#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int n; 
    cin >> n;

    int A[n];
    for (int &i : A)
        cin >> i;
    
    int ans = 0;
    for (int k = 1; k <= n; k++){
        if (n % k == 0){
            int g = 0;
            for (int i = 0; i + k < n; i++)
                g = __gcd(g, abs(A[i + k] - A[i]));
            ans += (g != 1);
        }
    }
    cout<<ans<<"\n";
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