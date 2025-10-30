#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector <tuple<int,int,int>> ans;
    set <tuple<int,int,int>> avl, avl0;

    int x = 0, y = 0;
    for(int i = 0; i < n+10; i++){
        int b = 3*x + 1 + 3*y + 1;
        avl.insert({b, 3*x + 1, 3*y + 1});
        avl.insert({b+1, 3*x + 1, 3*y + 2});
        avl.insert({b+1, 3*x + 2, 3*y + 1});
        avl.insert({b+4, 3*x + 2, 3*y + 2});
        avl0.insert({b, 3*x + 1, 3*y + 1});
        x++, y--;
        if(y < 0) y = x, x = 0;
    }
    int idx = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(a == 1){
            auto p = *avl.begin();
            avl.erase(p);
            ans.push_back(p);
            if(avl0.count(p)) avl0.erase(p);
            idx++;
        }
        else{
            auto p = *avl0.begin();
            avl0.erase(p);
            avl.erase(p);
            ans.push_back(p);
        }
    }
    for(auto [b,x,y] : ans){
        cout << x << " " << y << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2090/problem/C