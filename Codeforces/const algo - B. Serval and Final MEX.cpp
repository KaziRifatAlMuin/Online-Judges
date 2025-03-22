#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector <int> v(n), z;
    vector <pair<int,int>> ans;
    int zero = 0, shift = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] == 0){
            zero++;
            z.push_back(i+1);
        }
    }
    if(zero == n){
        ans.push_back({1, 2});
        ans.push_back({2, n-1});
        ans.push_back({1, 2});
    }
    else{
        if(zero == 0){
            ans.push_back({1, n});
        }
        else if(zero == 1){
            if(v[0] == 0){
                ans.push_back({1, 2});
                ans.push_back({1, n-1});
            }
            else{
                ans.push_back({z[0]-1, z[0]});
                ans.push_back({1, n-1});
            }
        }
        else{
            if(v[0] == 0){
                if(v[1] != 0){
                    ans.push_back({1, 2});
                    ans.push_back({2, n-1});
                    ans.push_back({1, 2});
                }
                else{
                    ans.push_back({1, 2});
                    if(zero == 2) ans.push_back({1, n-1});
                    else{
                        ans.push_back({2, n-1});
                        ans.push_back({1, 2});
                    }
                }
            }
            else{
                if(z[0] == n-1 && z[1] == n){
                    ans.push_back({z[0], z[1]});
                    ans.push_back({1, n-1});
                }
                else{
                    ans.push_back({1, z[0]});
                    ans.push_back({2, n - (z[0] - 1)});
                    ans.push_back({1, 2});
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto [x,y] : ans){
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
