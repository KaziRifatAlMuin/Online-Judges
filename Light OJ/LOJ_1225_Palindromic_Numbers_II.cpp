#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    ll n; cin >> n;
    ll last, first, div;
    ll digit = log10(n);
    for(int i = 0; i < (digit + 1) / 2 ; i++){
        div = pow(10, digit - i * 2);
        first = n / div;
        last = n % 10;
        if(first != last){
            cout << "No\n";
            return;
        }
        n -= (first * div);
        n /= 10;
    }
    cout << "Yes\n";
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