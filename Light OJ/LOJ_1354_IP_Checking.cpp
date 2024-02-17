#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int ip1[4], ip2[4];
    char c;
    cin >> ip1[0] >> c >> ip1[1] >> c >> ip1[2] >> c >> ip1[3];
    cin >> ip2[0] >> c >> ip2[1] >> c >> ip2[2] >> c >> ip2[3];
    for(int i = 0; i < 4; i++){
        int num1 = ip1[i], num2 = 0, m = 1;
        int temp = ip2[i];
        while(temp){
            int d = temp % 10;
            num2 += (d * m);
            m *= 2;
            temp /= 10;
        }
        if(num1 != num2){
            cout << "No\n";
            return;
        }
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