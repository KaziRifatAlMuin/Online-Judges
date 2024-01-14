#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int n, answer = 0; cin >> n;
    vector<int>a(n);
    for(auto &i : a) cin >> i;

    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {

            int k = n / i, g = 0;

            for(int j = 0; j < k; j++) {
                int diff = 0;
                for(int l = j; l < n; l += k) {
                    diff = __gcd(diff, abs(a[j] - a[l]));
                }
                g = __gcd(g, diff);
            }

            answer += (g != 1);
        }
    }

    cout << answer << "\n";
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