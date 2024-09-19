#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e7 + 5;
long long const M = 1e10 + 5;

bool NotPrime[N + 5];
vector <ll> primes;
vector <ll> sqr;
set <ll> st;

void seive()
{
    for(ll i = 2; i * i <= N; i++){
        if(!NotPrime[i]){
            for(ll j = i * i; j <= N; j += i){
                NotPrime[j] = true;
            }
        }
    }
    for(ll i = 2; i < N; i++){
        if(!NotPrime[i]){
            primes.push_back(i);
            if(i * i * 1ll <= M){
                sqr.push_back(i*i);
                st.insert(i * i);
            }
        }
    }
    sort(sqr.begin(), sqr.end());
}



void solve()
{
    ll n, a, b, c;
    cin >> n;
    ll lim = sqr.size();
    // cout << lim << "\n";
    // for(auto x : sqr){
    //     cout << x << " ";
    // }
    // cout << "\n";

    for(int j = 0; j < lim; j++){
        b = sqr[j];
        c = n - (4 + b);
        if(st.count(c) > 0 && c != a && c != b){
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin >> t;
    seive();
    while(t--){
        solve();
    }
    return 0;
}
