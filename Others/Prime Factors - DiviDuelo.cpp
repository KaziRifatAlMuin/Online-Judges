#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 7;

ll spf[N];
vector <ll> primes;

void sieve() {
    for(ll i = 1; i < N; i++) spf[i] = i;
    for(ll i = 2; 1ll * i * i < N; i++) {
        if(spf[i] == i) { // i is prime
            for(ll j = i * i; j < N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
    for(ll i = 2; i < N; i++){
        if(spf[i] == i) primes.push_back(i);
    }
}

vector <pair<ll,ll>> factor(ll n) {
    vector <pair<ll,ll>> fact;
    for(auto p : primes){
        if(1ll * p * p > n) break;
        if(n % p == 0){
            ll power = 0;
            while(n % p == 0){
                n /= p;
                power++;
            }
            fact.push_back({p, power});
        }
    }
    if(n > 1) fact.push_back({n, 1});
    return fact;
}

void solve()
{
    ll n;
    cin >> n;
    vector <pair<ll,ll>> fact = factor(n);
    bool ok = true;
    bool issq = ceil(sqrtl(n)) == floor(sqrtl(n));
    if(issq){
        cout << "N\n";
        return; 
    }
    for(auto [x,y] : fact){
        if(y > 1) ok = false;
    }
    // ll a = pow(2,5) * pow(3,7) * pow(5,3) * pow(1e9 + 7, 1);
    // cout << a << "\n";
    if(fact.size() == 1) cout << "Y\n";
    else if(fact.size() == 2 && ok) cout << "Y\n";
    else cout << "N\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t = 1, st = clock();
    // cin >> t;
    sieve();
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://vjudge.net/problem/QOJ-8508