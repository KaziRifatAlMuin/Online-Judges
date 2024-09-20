#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    string s, f;
    int n;
    cin >> n >> s >> f;
    int zero = 0, one = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] != f[i]){
    		f[i] == '0' ? zero++ : one++;
    	}
    }
    cout << max(zero, one) << "\n";
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