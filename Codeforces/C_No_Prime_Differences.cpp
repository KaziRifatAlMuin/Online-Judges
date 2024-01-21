#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector < vector <int> > v;
    int num = 1;
    for(int i = 0; i < n; i++){
        vector <int> tmp;
        for(int j = 0; j < m; j++){
            tmp.push_back(num++);
        }
        v.push_back(tmp);
    }
    for(int i = 1, k = 0; k < n; i += 2, k++){
        if(i >= n) i = 0;
        for(int j = 0; j < m; j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
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