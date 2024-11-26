#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int first = -1, last = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '1' && first == -1) first = i;
        if(s[i] == '1') last = i;
    }
    multiset <ll> seg;
    ll len = last - first + 1;
    if(len > k) cout << "No\n";
    else if(first == -1){
        int cons = 0, cur = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '?'){
                cur++;
                cons = max(cons, cur);
            }
            else{
                seg.insert(cur);
                cur = 0;
            }
        }
        seg.insert(cur);
        if(cons == k && seg.count(cons) == 1) cout << "Yes\n";
        else cout << "No\n";
    }
    else{
        ll opt1 = 0, opt2 = 0;
        for(int i = first; i <= last; i++){
            if(s[i] == '0'){
                cout << "No\n";
                return;
            }
        }
        if(len == k){
            cout << "Yes\n";
            return;
        }
        for(int i = first - 1; i >= 0 && s[i] == '?'; i--) opt1++;
        for(int i = last + 1; i < n && s[i] == '?'; i++) opt2++;
        // cout << opt1 << " " << opt2 << " " << len << " ";
        if(opt1 + opt2 + len == k) cout << "Yes\n";
        else if(opt1 + opt2 + len > k && (opt1 == 0 || opt2 == 0)) cout << "Yes\n";
        else cout << "No\n";
    }
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
// https://atcoder.jp/contests/arc150/tasks/arc150_a?lang=en