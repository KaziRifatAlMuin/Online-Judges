#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

void test(string s){
    int n = s.size();
    for(int i = 0; i < n; i++){
        string temp = s;
        if(temp[i] == '0') temp[i] = '1';
        else temp[i] = '0';
        cout << temp << "\n";
    }
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0, up = 0, down = 0, zero = 0, one = 0, prev = 0;
    // test(s);
    for(int i = 0; i < n; i++){
        if(s[i] == '0') {
            zero++;
            one = 0;
        }
        else{
            one++;
            zero = 0;
        }
        if(zero == 1){
            up += (down + i);
            down = (n - i - 1);
        }
        else if(zero > 1){
            up += i;
            down += (n - i - 1);
        }
        else if(one == 1){
            up = 0;
            down++;
        }
        else if(one > 1){
            up = 1;
            down = 0;
        }
        ans = max({ans, up, down});
        // cout << up << " " << down << "\n";
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
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2106/problem/F