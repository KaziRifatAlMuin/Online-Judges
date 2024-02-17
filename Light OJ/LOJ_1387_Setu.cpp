#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int n; cin >> n;
    int money = 0;
    while(n--){
        string s; cin >> s;
        if(s == "donate"){
            int k; cin >> k;
            money += k;
        }
        else{
            cout << money << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ":\n";
        solve();
    }
    return 0;
}