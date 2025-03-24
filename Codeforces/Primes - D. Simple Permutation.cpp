#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 2e5 + 7;

bool NotPrime[N];
vector <int> primes;

void seive()
{
    NotPrime[1] = 1; NotPrime[0] = 1;
    for(ll i = 4; i < N; i += 2) NotPrime[i] = 1;
    for(ll i = 3; i * i < N; i += 2){
        if(!NotPrime[i]){
            for(ll j = i * i; j < N; j += (i+i)) NotPrime[j] = 1;
        }
    }
    for(ll i = 2; i < N; i++){
        if(!NotPrime[i]) primes.emplace_back(i);
    }
}

void solve() {
    int n;
    cin >> n;
    int p = 2;
    for(int i = n/3; i <= 2*n/3; i++){
        if(!NotPrime[i]){
            p = i;
            break;
        }
    }
    // Bertrand's postulate: there must be a prime p such that n < p < 2n
    int lim = max(1, n/3 - 1) , mini = p, maxi = p;
    cout << p << " ";
    for(int i = 1, j = 2; i < lim; i++, j++){
        int c;
        c = (i & 1 ? p - j/2 : p + j/2);
        mini = min(c, mini);
        maxi = max(c, maxi);
        cout << c << " ";
    }
    for(int i = mini - 1; i > 0; i--) cout << i << " ";
    for(int i = maxi + 1; i <= n; i++) cout << i << " ";
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    seive();
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2090/problem/D