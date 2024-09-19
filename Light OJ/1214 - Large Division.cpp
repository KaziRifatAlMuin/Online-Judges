#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
long long int const MOD = 1e9 + 7;

void solve()
{
    string bignum;
    ll div;
    cin >> bignum >> div;
    ll len = bignum.size();
    ll num = 0, dig, j = 0;
    for(int i = 0; i < len; i++){
        if(bignum[i] == '-') continue;
        dig = bignum[i] - '0';
        num = num * 10 + dig;
        //cout << num << " ";
        if(num % div == 0 && i == len - 1){
            cout << "divisible" << endl;
            return;
        }
        else if(num >= div){
            num = num % div;
        }
    }
    cout << "not divisible" << endl;
}

int main()
{
    FAST_IO

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1, case_number = 1;
    cin >> t;
    while(t--)
    {
        cout << "Case " << case_number++ << ": ";
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
    