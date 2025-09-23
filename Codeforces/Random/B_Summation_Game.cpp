#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    ll n, k, x, sum = 0;
    cin >> n >> k >> x;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = n - 1, cnt = 0; cnt < x && i >= 0; i--, cnt++){
        v[i] *= -1;
    }
    for(auto x : v) sum += x;
    int ix = n - x - 1, mx = n - 1;
    ll ans = sum;
    while(k--){
        //cout << sum << " " ;
        if(ix >= 0) sum = sum + abs(v[mx]) - 2 * v[ix];
        else sum = sum + abs(v[mx]);
        mx--; ix--;
        ans = max(ans, sum);
    }
    cout << ans << "\n";
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