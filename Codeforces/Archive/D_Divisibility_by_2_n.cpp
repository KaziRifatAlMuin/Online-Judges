#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

ll two(ll n){
    int cnt = 0;
    while(n % 2 == 0){
        n /= 2; 
        cnt++;
    }
    return cnt;
}

void solve()
{
    int n; cin >> n;
    vector <int> a(n);
    priority_queue <int> b;
    for(int &x : a) cin >> x;
    ll ans = 0;
    for(int ix = 1; ix <= n; ix++){
        b.push(two(ix));
        ans += two(a[ix - 1]);
    }
    if(ans >= n){
        cout << "0\n";
    }
    else{
        ll cnt = 0;
        for(auto x = b.top(); x > 0; x = b.top()){
            ans += x;
            if(ans >= n){
                cout << cnt + 1 << "\n";
                return;
            }
            else{
                cnt++;
            }
            b.pop();
        }
        cout << -1 << "\n";
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