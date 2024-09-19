#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int n; cin >> n;
    vector <int> a(n+1, 2);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += (a[i] - a[i-1] + 4) / 5;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}