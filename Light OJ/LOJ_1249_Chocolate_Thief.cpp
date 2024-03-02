#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    map <string, ll> volume;
    map <ll, string> name;
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        ll a, b, c;
        cin >> s >> a >> b >> c;
        volume[s] = a * b * c;
        name[a * b * c] = s;
    }
    if(name.size() == 1) cout << "no thief\n";
    else{
        auto it = --name.end();
        cout << it->second << " took chocolate from " << name.begin()->second << "\n";
    }
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