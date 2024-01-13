#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int &e : a) cin >> e;
    vector <int> divisor;
    for(int i = 2; i < sqrt(n) + 3; i++){
        if(n % i == 0){
            divisor.push_back(i);
            if(i != n/i) divisor.push_back(n/i);
        }
    }
    sort(divisor.begin(), divisor.end());
    divisor.pop_back();
    int ans = 1, m = 2;
    for(auto d : divisor){
        int len = n/d;
        int flag = 1;
        for(int i = 0; i < len && flag; i++){
            for(int j = i; j < n; j += d){
                if(a[i] != a[j] || (a[i] % m != (a[j] % m))){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) ans++;
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