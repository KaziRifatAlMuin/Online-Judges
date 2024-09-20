#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int n; cin >> n;
    vector <int> where(n + 1);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        where[x] = i;
    }
    if(n == 1){
        cout << "0\n";
        return;
    }
    int L = (n + 1) / 2; // n = 5, L = 3, R = 3
    int R = (n + 2) / 2; // n = 6, L = 3, R = 4
    int ans = (n + 1) / 2;
    while(L >= 1 && (L == R || (where[L] < where[L + 1] && where[R - 1] < where[R]))){
        L--;
        R++;
        ans--;
    }
    cout << ans << "\n";
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