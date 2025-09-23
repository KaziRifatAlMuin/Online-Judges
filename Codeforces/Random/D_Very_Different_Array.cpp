#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    ll n , m;
    cin >> n >> m;
    vector <ll> a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll first = 0, last = n - 1, mini = 0, maxi = m - 1, ans = 0;
    while(first <= last){
        ll beg = abs(a[first] - b[maxi]);
        ll end = abs(a[last] - b[mini]);
        if(beg > end){
            ans += beg;
            first++;
            maxi--;
        }
        else{
            ans += end;
            last--;
            mini++;
        }
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