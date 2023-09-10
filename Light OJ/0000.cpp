#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
long long int const MOD = 1e9 + 7;

string str;
void findNthDigit(int p, int q, int N)
{
    int res;
    while (N > 0) {
        N--;
        p *= 10;
        res = p / q;
        str.push_back(res + '0');
        p %= q;
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    findNthDigit(1, n, 1000000);
    cout << str[m-1] << "\n";
}

int main()
{
    FAST_IO

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1, case_number = 1;
    //cin >> t;
    while(t--)
    {
        //cout << "Case " << case_number++ << ":\n";
        solve();
    }
    return 0;
}

/*


Coded by RifatALmuiN

Input
_______________________________

_______________________________


Output
_______________________________

_______________________________


*/
    