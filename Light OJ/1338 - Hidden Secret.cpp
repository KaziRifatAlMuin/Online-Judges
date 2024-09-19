#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 10056;
int const N = 1007;

void solve()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);

    a.erase(remove(a.begin(), a.end(), ' '), a.end());
    b.erase(remove(b.begin(), b.end(), ' '), b.end());

    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    if(a == b) cout << "Yes\n";
    else cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    cin.ignore();
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}