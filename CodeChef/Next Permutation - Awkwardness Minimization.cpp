#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

set <string> getPerm(string s) {
    int n = s.size();
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = i;
    set <string> st;
    do{
        string ss = s;
        // cout << ss << " ";
        for(int i = 0; i < n; i++){
            ss[i] = s[v[i]];
        }
        st.insert(ss);
    } while (next_permutation(v.begin(), v.end()));
    return st;
}

void solve() {
    string s;
    cin >> s;
    ll b = 0, g = 0, ans = 0, n = s.size();
    for(auto x : s){
        if(x == 'b') b++;
        else g++;
    }
    if(g > b) swap(g, b);
    // bbbb___gbgbgbgb___bbbb
    ll prev = g * g;
    ans += prev;
    for(int i = 1; i < g; i += 2){
        ll cur = prev - 2 * (g - i);
        ans += 2 * cur;
        prev = cur;
        if(g % 2 == 0 && i == g-1) ans -= cur;
    }
    prev = g * g;
    for(int i = 0; i < b-g; i++){
        if(i & 1){
            ans += prev + g;
            prev += g;
        }
        else ans += prev;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://vjudge.net/problem/CodeChef-AWKMINI