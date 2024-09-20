#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
ll mod = 1e9 + 7;

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;

    if (n <= 2) {
        cout << stoll(s) << "\n";
        return;
    }

    int zero = 0;
    for(auto x : s){
        if(x == '0') zero++;
    }

    if(zero){
        if(n == 3 && zero == 1 && s[1] == '0'){}
        else{
            cout << 0 << "\n";
            return;
        }
    }

    vector<ull> nums[22];
    for(int merge = 0; merge < n; ++merge) {
        nums[merge].clear();
        for(int i = 0; i < n;) {
            if(i == merge && i + 1 < n) {
                int a = s[i] - '0';
                int b = s[i + 1] - '0';
                nums[merge].push_back(a * 10 + b);
                i += 2;
            } 
            else {
                nums[merge].push_back(s[i] - '0');
                ++i;
            }
        }
    }
    ull ans = ULLONG_MAX, res = 0;
    for(int i = 0; i < n - 1; i++){
        for(auto x : nums[i]){
            // cout << x << " ";
            if(x != 1) res += x;
        }
        ans = min(ans, res);
        res = 0;
        // cout << "\n";
    }
    cout << max(1ull, ans) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}