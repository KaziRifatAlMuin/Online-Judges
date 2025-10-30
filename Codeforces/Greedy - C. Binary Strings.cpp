#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string xorStrings(string a, string b) {
    int len = max(a.size(), b.size());
    a = string(len - a.size(), '0') + a;
    b = string(len - b.size(), '0') + b;
    string res(len, '0');
    for(int i = 0; i < len; i++){
        res[i] = (a[i] != b[i]) ? '1' : '0';
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    ll l1 = 1, r1 = n, l2 = 1, r2 = 1;

    if(count(s.begin(), s.end(), '1') == n){
        cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
        return;
    }

    ll k = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') {
            k = n - i;
            break;
        }
    }

    priority_queue<tuple<string, int, int>> q;

    for(int i = 0; i + k <= n; i++){
        string sub = s.substr(i, k);
        q.push({xorStrings(s, sub), i + 1, i + k});
    }

    auto[a,b,c] = q.top();
    l2 = b, r2 = c;
    cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// https://codeforces.com/contest/2048/problem/C