#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define SetBit(x, k) (x |= (1ll << k))
#define ClearBit(x, k) (x &= ~(1ll << k))
#define CheckBit(x, k) ((x >> k) & 1)
#define PowerOf2(v) (v && !(v & (v - 1)))
#define to_Binary(n) bitset<sizeof(n) * 1>(n).to_string()
const int N = 3e5 + 7;

void solve() 
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        if(i == n) cout << 3 << "\n";
        else cout << 7 << " ";
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
