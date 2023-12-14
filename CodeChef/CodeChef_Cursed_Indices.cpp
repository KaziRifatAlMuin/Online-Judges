#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() 
{
    ll n;
    cin >> n;
    vector <ll> ans;
    multiset <ll> st, later;
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        st.insert(a);
    }
    ll sum = 0;
    ll cnt = 0;
    for(auto x : st){
        if(x > sum){
            ans.push_back(x);
            ++cnt;
            sum += x;
        }
        else{
            later.insert(x);
        }
    }
    for(auto x : later){
        ans.push_back(x);
    }
    cout << n - cnt << "\n";
    for(auto x : ans){
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
