#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int n; cin >> n;
    set <ll> t1, t2, t3;
    for(int i = 0; i < n; i++){
        int type, k;
        cin >> type >> k;
        if(type == 1) t1.insert(k);
        else if(type == 2) t2.insert(k);
        else t3.insert(k);
    }
    ll L = 0, U = 1e9 + 7;
    for(auto x : t1) L = max(L, x);
    for(auto x : t2) U = min(U, x);
    if(L > U) cout << 0 << "\n";
    else{
        int ans = U - L + 1;
        for(auto x : t3){
            if(x >= L && x <= U) ans--;
        }
        cout << ans << "\n";
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