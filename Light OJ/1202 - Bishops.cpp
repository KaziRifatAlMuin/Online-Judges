#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if(abs(r2 - r1) == abs(c2 - c1)){
        cout << 1 << "\n";
    }
    else if(((r1 + c1) % 2) != ((r2 + c2) % 2)){
        cout << "impossible\n";
    }
    else{
        cout << 2 << "\n";
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