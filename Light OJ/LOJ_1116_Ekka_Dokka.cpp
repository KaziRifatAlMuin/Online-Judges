#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 10056;
int const N = 1007;

void solve()
{
    ll w, p = 0;
    cin >> w;
    while(w % 2 == 0){
        w /= 2;
        p++;
    }
    if(p == 0) cout << "Impossible\n";
    else cout << w << " " << (1 << p) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    cin.ignore();
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}