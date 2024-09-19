#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 5005;

void solve()
{
    double x, y;
    cin >> x >> y;
    double dis = x * 10;
    for(int k = 1; k < 1000; k++){
        dis += 100;
        double speed = dis / (10 + k);
        if(speed >= y){
            // cout << speed << " ";
            cout << k << "\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
