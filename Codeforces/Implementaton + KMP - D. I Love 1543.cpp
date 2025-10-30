#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> build_lps(string p) {
    vector<int> lps(p.size());
    int j = 0;
    for(int i = 1; i < p.size(); ){
        if(p[i] == p[j]){
            lps[i] = j + 1;
            ++i, j++;
        }
        else{
            if(j != 0) j = lps[j - 1];
            else lps[i] = 0, ++i;
        }
    }
    return lps;
}

int kmp(string s, string p) {
    vector<int> lps = build_lps(p);
    int psz = p.size(), sz = s.size(), ans = 0;
    int i = 0, j = 0; // i -> s, j -> p;
    while(i < s.size()){
        if(s[i] == p[j]){
            ++i, j++;
        }
        else{
            if(j != 0) j = lps[j - 1];
            else ++i;
        }
        if(j == p.size()){
            ans++;
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    string ans = "";
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    while(top <= bottom && left <= right){
        string cur = "";
        for(int i = left; i <= right; i++){
            cur += s[top][i];
        }
        top++;
        for(int i = top; i <= bottom; i++){
            cur += s[i][right];
        }
        right--;
        if(top <= bottom) {
            for(int i = right; i >= left; i--){
                cur += s[bottom][i];
            }
            bottom--;
        }
        if(left <= right) {
            for(int i = bottom; i >= top; i--){
                cur += s[i][left];
            }
            left++;
        }
        string extra = "";
        for(int i = 0; i < 3 && i < cur.size(); i++){
            extra += cur[i];
        }
        cur += extra;
        ans += cur + " ";
    }
    cout << kmp(ans, "1543") << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
// https://codeforces.com/contest/2036/problem/D