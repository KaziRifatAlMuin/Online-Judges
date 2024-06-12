#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 5000;

void solve()
{
    ll n, cs = 1;
    while(1){
        cin >> n;
        if(n == 0) break;
        vector <int> a(n+1), b(n+1), c(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        int state[N+5][11];
        bool IsSleep[N+5][11];
        for(int i = 1; i <= n; i++){
            state[1][i] = (c[i] - 1) % ((a[i]+b[i]));
            if(state[1][i] >= a[i] && state[1][i] < (a[i]+b[i])){
                IsSleep[1][i] = true;
            }
            else{
                IsSleep[1][i] = false;
            }
        }
        cout << "Case " << cs++ << ": ";
        bool flag = 1;
        for(int k = 1; k <= N && flag; k++){
            ll cnt = 0;
            bool willSleep = false;
            for(int i = 1; i <= n; i++){
                if(IsSleep[k][i]) cnt++;
            }
            if(cnt > n/2) willSleep = true;
            if(cnt == 0){
                cout << k << "\n";
                flag = 0;
            }

            for(int i = 1; i <= n; i++){
                if(state[k][i] == a[i] - 1 && !willSleep){
                    state[k+1][i] = 0;
                }
                else{
                    state[k+1][i] =( state[k][i] + 1) % (a[i]+b[i]);
                }

                if(state[k+1][i] >= a[i] && state[k+1][i] < (a[i]+b[i])){
                    IsSleep[k+1][i] = true;
                }
                else{
                    IsSleep[k+1][i] = false;
                }
            }
        }
        if(flag) cout << -1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}