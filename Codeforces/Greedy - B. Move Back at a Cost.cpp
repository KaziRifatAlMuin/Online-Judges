#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector <int> v(n), a, sv;
    map <int, int> mp, cur;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    sv = v;
    sort(sv.begin(), sv.end());
    sv.erase(unique(sv.begin(), sv.end()), sv.end());
    int last = 1e9;
    for(int i = 0, j = 0; i < n; i++){
        int x = v[i];
        if(x == sv[j] && x <= last){
            a.push_back(x);
            cur[x]++;
            while(j < sv.size() && cur[sv[j]] == mp[sv[j]]) j++;
        }
        else{
            a.push_back(x+1);
            cur[x]++;
            last = min(last, x + 1);
        }
    }
    sort(a.begin(), a.end());
    for(auto x : a){
        cout << x << " ";
    }
    cout << "\n";
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
// https://codeforces.com/contest/2046/problem/B