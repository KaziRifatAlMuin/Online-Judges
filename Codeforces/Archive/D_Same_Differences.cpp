#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x; //check
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[a[i] - i]++;
    }
    ll ans = 0;
    for(auto x : mp){
        ans += (ll)x.second * (x.second - 1) / 2;
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