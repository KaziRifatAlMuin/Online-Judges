#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 105;

int spf[N];
vector <int> primes;
int cnt[N][N];

void seive(){
    for(ll i = 1; i < N; i ++) spf[i] = i;
    for(ll i = 2; i < N; i += 2) spf[i] = 2;
    for(ll i = 3; i * i < N; i += 2){
        if(spf[i] == i){
            for(ll j = i * i; j < N; j += (i+i)){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }

    for(ll i = 2; i < N; i++){
        if(spf[i] == i) primes.emplace_back(i);
    }
}

vector <pair<int,int>> factor(ll n){
    vector <pair<int,int>> fact;
    while(n > 1){
        ll p = spf[n];
        ll power = 0;
        while(n % p == 0){
            n /= p;
            power++;
        }
        fact.push_back({p, power});
        
    }
    return fact;
}

void pre(){
    seive();
    for(int i = 1; i < N; i++){
        for(int j = 0; j < N; j++) cnt[i][j] = cnt[i-1][j];
        int n = i;
        while(n > 1){
            ll p = spf[n];
            ll power = 0;
            while(n % p == 0){
                n /= p;
                power++;
            }
            cnt[i][p] += power;
        }    
    }
}

void solve() {
    int n;
    while(1){
        cin >> n;
        if(n == 0) break;
        cout << setw(3) << n << "! =";
        for(int i = 0; primes[i] <= n; i++){
            if(i == 15) cout << "\n" << setw(9) << cnt[n][primes[i]];
            else cout << setw(3) << cnt[n][primes[i]];
        }
        cout << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    pre();
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}