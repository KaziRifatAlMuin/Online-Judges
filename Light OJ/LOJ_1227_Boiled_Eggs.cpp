#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int n, max_egg, max_weight;
    cin >> n >> max_egg >> max_weight;
    int w[n];
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    sort(w, w + n);
    ll sum = 0;
    for(int i = 0;; i++){
        sum += w[i];
        if(sum > max_weight || i == min(max_egg, n)){
            cout << i << "\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}